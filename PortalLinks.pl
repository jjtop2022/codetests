#!/usr/bin/perl

# This script is a 2 step process: 
####################################################################
# Firstly, we need to parse out information in the XML files located in:
# /ms/dist/ebi/eps_config/xml/epi_installations.xml 1. (installation file)
# that reads the portal assignment file 2. (list of sub-portals): 
# /ms/dist/ebi/eps_config/xml/epi_assignments.xml, this file is
# then referenced by /ms/dist/ebi/eps_config/xml/epi_portalrefs.xml 
# which contains information on the 3. (location of the sub-portal configuration)
# file the final file. This is a listing of the sub-portal configuration file 
# we need which is scattered throughout the AFS space and maintained by 
# individual developers. 4. (portal release).
####################################################################
# The second step: Use this information maintained in the buffers (arrays)
# and create symbolic links from the sub-portals config files on the machine 
# to the portal server directories. Using symlink command we can 
# create these links.

# Parameters:
# -c => create symbolic links
# -d => delete existing links
# -v => verbose mode
# -s => portal option

####################################################################

use XML::Parser;
use Getopt::Std;

$debug=0;  #used for debugging purposes 

my $install_loc = q(/ms/dist/ebi/eps_config/xml/epi_installations.xml);
my $assign_loc = q(/ms/dist/ebi/eps_config/xml/epi_assignments.xml);
my $ref_loc = q(/ms/dist/ebi/eps_config/xml/epi_portalrefs.xml);

# global variables to be used throughout the script to extract
# information out of the installation XML files.
my $install_name;  #installation name parameter on command line

my $portinstall_name;  #<PI>.<Name>, epi_installations.xml
my $server;  #<PI>.<Server>, epi_installations.xml
my $server_root; #<PI>.<PortalServerRoot>, epi_installations.xml
my $executeID;   #<PI>.<ExecutionID>, epi_installations.xml 

my $assign_install;  #<PA>.<PortalInstallation>, epi_assignments.xml
my $assign_portal;   #<PA>.<Portal>, epi_assignments.xml

my $ref_portal;    #<PR>.<Portal>, epi_portalrefs.xml
my $ref_conf_file; #<PR>.<ConfigurationFile>, epi_portalrefs.xml

# used for creating symlinks
my $final_name;      #<Portal>.<Name>, developer XML file
my $final_metaproj;  #<Portal>.<Metaproject>, developer XML file
my $final_proj;      #<Portal>.<Project>, developer XML file
my $final_release;   #<Portal>.<Release>, developer XML file
my $final_state;     #<Portal>.<State>, developer XML file


############ OPTIONAL VARIABLES ##########
my $beandir_root;    #Holds optional PRESENTATION root
my $bean_count = 0;  #optional presentation counter

my $pbddir_optional; #Holds optional PBD directory.
my $pbd_count = 0;   #PBD directory
my @modname_pbd =(); #Holds optional PBD's if any

my $config_optional; #Holds optional config file
my $config_count = 0;#INDICATOR of optional config

my $jar_dir;         #Holds optional JAR directory
my $jar_count = 0;   #JAR file indicator
my @jar_files =();   #Holds filenames

###### <Template> variables ######
# Make arrays because we could have x number of
# tags containing optional links
my @chrome_dir =();  #holds chrome directory specific links
my @footer_dir =();
my @header_dir =();
my @index_dir = ();
my @nav_dir = ();
my @tab_dir = ();
# <template> optional directory holders
my $chrome_option;
my $header_option;
my $footer_option;
my $index_option;
my $nav_option;
my $tab_option;
# <template> counters
my $chrome_count = 0; 
my $head_count = 0;
my $foot_count = 0;
my $index_count = 0;
my $nav_count = 0;
my $tab_count = 0;
######### END OF OPTIONAL VARIABLES ########

my $proj_root;      # Project root directory for symlinks

my $checker = 0;    # indicator flag
my $opt_print = 0;  # flag for no options at command line
my $dash_s = 0;     # flag for -s portalname option

###################################################################
# Get options for parameters.
# Required input is the installation name.

getopts("vc:d:s:");

if ($debug) {
   if ($opt_c) {
     print "Specified create symbolic links option.\n";
     print ".......................................\n";
   }elsif ($opt_d) {
     print "Specified delete existing links option.\n";
     print ".......................................\n";
   }elsif ($opt_v) {
     print "Specified verbose option.\n";
     print ".........................\n";
   }
} 

if (!$opt_c and !$opt_d) {
   if ($opt_v) {
      print "You specified a verbose printout of ";           
      ($install_name) = @ARGV;
      print "$install_name\n";           
      $opt_print = 1;
      
   }elsif (!$opt_v and (@ARGV == 1 or @ARGV == 2)) {
      print "You specified a default printout.\n";
      if (@ARGV == 1) {
        ($install_name) = @ARGV;
      }elsif (@ARGV == 2) {  
        # 2 arguments means portal name was given too 
        ($install_name, $assign_portal) = @ARGV;
        $dash_s++;
      }
      $opt_print = 1;

   }else {
      die "Enter options followed by installation name!\n";
   }
}

if ($opt_c) {
   $install_name = $opt_c;
}elsif ($opt_d) {
   $install_name = $opt_d;
}
print "Installation input name: $install_name\n\n" if $opt_v;

# a portal name was specified.
if ($opt_s) {
   $assign_portal = $opt_s;
   $dash_s++;
   print "Portal name specified: $assign_install\n" if $opt_v; 
}

###################################################################
# 1ST STEP: parse the contents out
# check files for errors, NOTE: only works on XML files with a root

$parseCheck = new XML::Parser(ErrorContext => 3);
print "Checking syntax of $install_loc...\n" if $opt_v;
$parseCheck->parsefile($install_loc);
print "XML Syntax for $install_loc checked...\n" if $opt_v;

$parseCheck = new XML::Parser(ErrorContext => 3);
print "Checking syntax of $assign_loc...\n" if $opt_v;
$parseCheck->parsefile($assign_loc);
print "XML Syntax for $assign_loc checked...\n" if $opt_v;

$parseCheck = new XML::Parser(ErrorContext => 3);
print "Checking syntax of $ref_loc...\n" if $opt_v;
$parseCheck->parsefile($ref_loc);
print "XML Syntax for $ref_loc checked...\n" if $opt_v;


############################################################
########### Parse the 1st file and get the variables #######

$p1 = new XML::Parser (Style => 'Tree');
$parseTree = $p1->parsefile($install_loc);
$rootNode = $parseTree->[0];
$machineArray = $parseTree->[1];

print "\n\nReading $install_loc file...\n" if $opt_v;
print "rootNode=<$rootNode>\n" if $opt_v;

# Step through each of the <PortalInstallation> tags
for (my $i=1; $i<@$machineArray; $i+=2) {

   $element = $machineArray->[$i];
   $element =~ s/^\s*(.*?)\s*$/$1/;  # strip whitespace
   $elementcontent = $machineArray->[$i+1]; # inside tags
 
  ##### get rid of the empty tags #####
  if (SkipWhiteSpace($element, $elementcontent)) {
      next;
  }

  ##### get the inside variables #####
  ## We must match the $portinstall_name, with
  ## $install_name, fill the rest.    
  if ($element eq "PortalInstallation") {
      if (getVariablesInstall()) {
         last;
      }
  }   
  print "machineArray[$i]=<$element>\n" if $debug;
  print "machineArray[$i+1]=<$elementcontent>\n" if $debug;
}

############################################################
# check if Installation name command-line parameter is valid
if ($checker == 0) {
   die "Installation name is not valid.\n";
}

##########################################################
# CHECK: Verify ownership of files and script ID being run 
$currentuser = `whoami`;
chomp ($currentuser);
print "Username = <$currentuser>\n" if $opt_v;
if ($currentuser ne $executeID) {
   die "NOTE! Script must be run by $executeID. Please login as $executeID to run script.\n";
}


###########################################################
######### Parse the 2nd file and get the variables ########

$p1 = new XML::Parser (Style => 'Tree');
$parseTree = $p1->parsefile($assign_loc);
$rootNode = $parseTree->[0];
$machineArray = $parseTree->[1];

print "\nReading $assign_loc file...\n" if $opt_v;
print "rootNode=<$rootNode>\n" if $opt_v;

$checker = 0;
# Step through each of the <PortalAssignment> tags
for (my $i=1; $i<@$machineArray; $i+=2) {

   $element = $machineArray->[$i];
   $element =~ s/^\s*(.*?)\s*$/$1/;  # strip whitespace
   $elementcontent = $machineArray->[$i+1]; # inside tags
 
  ##### get rid of the empty tags #####
  if (SkipWhiteSpace($element, $elementcontent)) {
      next;
  }
  ##### get the inside variables #####
  ## We must fill the $assign_portal, $assign_install.    
  if ($element eq "PortalAssignment") {
      if (getVariablesAssign()) {
         last;
      }
  }   
  print "machineArray[$i]=<$element>\n" if $debug;
  print "machineArray[$i+1]=<$elementcontent>\n" if $debug;

}


###########################################################
######### Parse the 3rd file and get the variables ########

$p1 = new XML::Parser (Style => 'Tree');
$parseTree = $p1->parsefile($ref_loc);
$rootNode = $parseTree->[0];
$machineArray = $parseTree->[1];

print "\nReading $ref_loc file...\n" if $opt_v;
print "rootNode=<$rootNode>\n" if $opt_v;

$checker = 0;
# Step through each of the <PortalReference> tags
for (my $i=1; $i<@$machineArray; $i+=2) {

   $element = $machineArray->[$i];
   $element =~ s/^\s*(.*?)\s*$/$1/;  # strip whitespace
   $elementcontent = $machineArray->[$i+1]; # inside tags
 
  ##### get rid of the empty tags #####
  if (SkipWhiteSpace($element, $elementcontent)) {
      next;
  }
  ##### get the inside variables #####
  ## We must fill the $ref_portal, $ref_conf_file.    
  if ($element eq "PortalReference") {
      if (getVariablesRefer()) {
         last;
      }
  }   
  print "machineArray[$i]=<$element>\n" if $debug;
  print "machineArray[$i+1]=<$elementcontent>\n" if $debug;

}

###########################################################
## Now goto the $ref_conf_file location and parse that file

chomp ($ref_conf_file);
$p1 = new XML::Parser (Style => 'Tree');
$parseTree = $p1->parsefile($ref_conf_file);
$rootNode = $parseTree->[0];
$machineArray = $parseTree->[1];

print "\nReading $ref_conf_file file...\n" if $opt_v;
print "rootNode=<$rootNode>\n" if $opt_v;

$checker = 0;
# Step through the <Portal> tags
for (my $i=1; $i<@$machineArray; $i+=2) {

  $element = $machineArray->[$i];
  $element =~ s/^\s*(.*?)\s*$/$1/;  # strip whitespace
  $elementcontent = $machineArray->[$i+1]; # inside tags
 
  ##### get rid of the empty tags #####
  if (SkipWhiteSpace($element, $elementcontent)) {
      next;
  }
  ## We must fill the $final_* variables.
  #### Get the <PortalName> variable ####    
  if ($element eq "PortalName") {
     if ($checker == 1) {
        last;
     }
     my $first_final = $elementcontent->[2];

     if ($first_final eq $ref_portal) {
        $final_name = $first_final;
        print "Portal name: $final_name\n" if $opt_v;
        $checker = 1;
     }
  } #### Get the <MetaProject> name ####
  elsif ($element eq "Metaproject") {
     $final_metaproj = $elementcontent->[2];
     if ($checker == 1) {
        print "Metaproject: $final_metaproj\n" if $opt_v;
     }   
  } #### Get the <Project> name ####
  elsif ($element eq "Project") {
     $final_proj = $elementcontent->[2];
     if ($checker == 1) {
        print "Project: $final_proj\n" if $opt_v;
     } 
  } #### Get the <Release> name ####
  elsif ($element eq "Release") {
     $final_release = $elementcontent->[2];
     if ($checker == 1) {
        print "Release: $final_release\n" if $opt_v;
     } 
  } #### Get the <State> name ####
  elsif ($element eq "PortalState") {
     $final_state = $elementcontent->[2];
     if ($checker == 1) {
        print "Portal State: $final_state\n" if $opt_v;
     } 
  } 
  ### Optional elements starting now. ########### 
  #### Get the <ModuleSet> name if available ####
  elsif ($element eq "ModuleSet") {     
     ModuleSet();
     print "Mod name: @modname_pbd\n" if $debug;
  }   
  #### Get the <TemplateSet> name if available ####
  elsif ($element eq "TemplateSet") {     
     TemplateSet();
     print "Chrome: @chrome_dir\n" if $debug;
     print "Header: @header_dir\n" if $debug;
     print "Index: @index_dir\n" if $debug;
     print "Nav: @nav_dir\n" if $debug;
     print "Tab: @tab_dir\n" if $debug;

  } #### Get the <JarSet> ####
  elsif ($element eq "JarSet") {
     JarSet();
     print "Jar: @jar_files\n" if $debug;
   
  }elsif ($element eq "CustomPropertiesFile") {
     $config_optional = $elementcontent->[2];
     $config_count++; 
  }   

}

########################################################
# rid all trailing characters
ChompIt();

# fill project root variable
FillProjRoot();

# goto server check we are on the right hostname
RshServerCheck();

########################################################
## Use information to create or delete symbolic links ##

if ($opt_c) {
   print "\nCreating option specified..\n" if $debug;
   print "..............................\n" if $opt_v;
   CreateSymLinks();

}elsif ($opt_d) {
   print "\nDeleting option specified..\n" if $debug;
   print "..............................\n" if $opt_v;
   DeleteSymLinks();

}elsif ($opt_print) {
   print "Printing links....\n" if $debug;
   PrintOut();
}

## END OF MAIN ###################################################
##################################################################
##################################################################



##################################################################
# Beginning sub functions

sub SkipWhiteSpace  {
  my ($tag, $content) = @_;
  if ( ($tag eq "0") && ($content =~ m/^\s*$/)) {
    return 1;
  }else{
    return 0;
  }
}

sub ChompIt {
  chomp($server);
  chomp($server_root);
  chomp($assign_portal);
  chomp($assign_install);
  chomp($ref_portal);
  chomp($final_name);
  chomp($final_metaproj);
  chomp($final_proj);
  chomp($final_release);
  chomp($final_state);
}

sub FillProjRoot {
   print "\n";
   if ($final_state eq "dev") {
      $proj_root = "/ms/dev/$final_metaproj/$final_proj/$final_release/install/common/$final_proj";  
      print "Project root: $proj_root\n" if $opt_v;

   }elsif ($final_state eq "QA") {
      $proj_root = "/ms/dist/$final_metaproj/PROJ/$final_proj/$final_release/common/$final_proj";
      print "Project root: $proj_root\n" if $opt_v;

   }elsif ($final_state eq "prod") {
      $proj_root = "/ms/dist/$final_metaproj/$final_proj";
      print "Project root: $proj_root\n" if $opt_v;
   }
}

sub RshServerCheck {
   print "Verifying are on server: $server\n" if $opt_v;
   my $temp = `uname -a`;
   print "$temp\n" if $opt_v;
   $temp = `hostname`;
   chomp($temp);
   if ($temp ne $server) {
      die "NOTE! Please login to $server before running the script.\n";
   }
}


# used for getting optional information in project XML files
sub ModuleSet {
   # loops through all the tags within <ModuleSet>
   for (my $i=1; $i<@$elementcontent; $i+=2) {
      $innertag = $elementcontent->[$i];
      $innercontent = $elementcontent->[$i+1];
  
      if (SkipWhiteSpace($innertag, $innercontent)) {
         next;
      }
      print "Optional innerelement = <$innertag>, content2=<$innercontent>\n" if $debug;
      
      if ($innertag eq "BeanDirectoryRoot") {
         $beandir_root = $innercontent->[2];
         print "Optional Bean Directory: $beandir_root\n" if $debug;
         $bean_count++;   
 
      }elsif ($innertag eq "PBDDirectory") {
         $pbddir_optional = $innercontent->[2];
         print "Optional PBDDirectory: $pbddir_optional\n" if $debug;
         $pbd_count++;

      }elsif ($innertag eq "ModuleName") {
         my $tempmod = $innercontent->[2];
         #add <ModuleName> contents to array
         push (@modname_pbd, $tempmod);         
  
      }
   }
}


# to get optional information within the <TemplateSet> tags
sub TemplateSet {
   #loop through all tags within <TemplateSet>
   for (my $i=1; $i<@$elementcontent; $i+=2) {
       $innertag = $elementcontent->[$i];
       $innercontent = $elementcontent->[$i+1];
    
       if (SkipWhiteSpace($innertag, $innercontent)) {
          next;
       }

       if ($innertag eq "Chrome") {
          #Loop through all the <Chrome> subtags
          for (my $j=1; $j<@$innercontent; $j+=2) {
             my $innerchrome = $innercontent->[$j]; 
             my $innerchrometag = $innercontent->[$j+1];

             if ($innerchrome eq "ChromeDirectory") {
                  $chrome_option = $innerchrometag->[2];
                  $chrome_count++;
                  print "Optional Chrome template dir: $chrome_option.\n" if $opt_v;
      
             }elsif ($innerchrome eq "ChromeName") {
                  my $tempchrome = $innerchrometag->[2];      
                  push (@chrome_dir, $tempchrome); 
             }
          }
          
       }elsif ($innertag eq "Header") {
           #Loop through all <Header> subtags
           for (my $j=1; $j<@$innercontent; $j+=2) {
               my $innerhead = $innercontent->[$j];
               my $innerheadtag = $innercontent->[$j+1];

               if ($innerhead eq "HeaderDirectory") {
                  $header_option = $innerheadtag->[2];
                  $head_count++;
                  print "Optional Header template dir: $header_option.\n" if $opt_v;

               }elsif ($innerhead eq "HeaderName") {
                  my $temphead = $innerheadtag->[2];
                  push (@header_dir, $temphead);
               }
           }

       }elsif ($innertag eq "Footer") {
          #Loop through all <Footer> subtags
          for (my $j=1; $j<@$innercontent; $j+=2) {
              my $innerfoot = $innercontent->[$j];
              my $innerfoottag = $innercontent->[$j+1];
              
              if ($innerfoot eq "FooterDirectory") {
                  $footer_option = $innerfoottag->[2];
                  $foot_count++;
                  print "Optional Footer template dir: $footer_option.\n" if $opt_v;

              }elsif ($innerfoot eq "FooterName") {
                  my $tempfoot = $innerfoottag->[2];
                  push (@footer_dir, $tempfoot);
              }
          }

       }elsif ($innertag eq "Index") {
           #Loop through <Index> subtags
           for (my $j=1; $j<@$innercontent; $j+=2) {
               my $innerindex = $innercontent->[$j];
               my $innerindextag = $innercontent->[$j+1];

               if ($innerindex eq "IndexDirectory") {
                  $index_option = $innerindextag->[2];
                  $index_count++;
                  print "Optional Index template dir: $index_option.\n" if $opt_v;

               }elsif ($innerindex eq "IndexName") {
                  my $tempindex = $innerindextag->[2];
                  push (@index_dir, $tempindex);
               }
           }

       }elsif ($innertag eq "Nav") {
           #Loop through <Nav> subtags
           for (my $j=1; $j<@$innercontent; $j+=2) {
               my $innernav = $innercontent->[$j];
               my $innernavtag = $innercontent->[$j+1];

               if ($innernav eq "NavDirectory") {
                  $nav_option = $innernavtag->[2];
                  $nav_count++;
                  print "Optional Nav template dir: $nav_option.\n" if $opt_v;

               }elsif ($innernav eq "NavName") {
                  my $tempnav = $innernavtag->[2];
                  push (@nav_dir, $tempnav);
               }
           }

       }elsif ($innertag eq "Tab") {
           #Loop through <Tab> subtags
           for (my $j=1; $j<@$innercontent; $j+=2) {
               my $innertab = $innercontent->[$j];
               my $innertabtag = $innercontent->[$j+1];

               if ($innertab eq "TabDirectory") {
                  $tab_option = $innertabtag->[2];
                  $tab_count++;
                  print "Optional Tab template dir: $tab_option.\n" if $opt_v;

               }elsif ($innertab eq "TabName") {
                  my $temptab = $innertabtag->[2];
                  push (@tab_dir, $temptab);
               }
           }
       }
   }

}

#Process Jarfile optional
sub JarSet {
   # loop through the <JarSet> properties
   for (my $i=1; $i<@$elementcontent; $i+=2) {
       $innertag = $elementcontent->[$i];
       $innercontent = $elementcontent->[$i+1];
           
       if (SkipWhiteSpace($innertag, $innercontent)) {
          next;
       }

       if ($innertag eq "JarDirectory") {
           $jar_dir = $innercontent->[2];
           $jar_count ++;
  	   print "Optional JAR directory: $jar_dir.\n" if $opt_v;
   
       }elsif ($innertag eq "JarFile") {
           my $tempjar = $innercontent->[2];
           push (@jar_files, $tempjar);
       }
   }
}


# For the installation file, fills up $portinstall_name, $server_root
# $executionID variables
sub getVariablesInstall {
  for (my $j=1; $j<@$elementcontent; $j+=2) {

     $innertag = $elementcontent->[$j];
     $content = $elementcontent->[$j+1];
     
     if (SkipWhiteSpace($innertag, $content)) {
        next;
     }
     print "innerelement = <$innertag>, content=<$content>\n" if $debug;     

     if ($innertag eq "Name") {
        my $first_install = $content->[2];

        if ($first_install eq $install_name) {
           print "Installation name: $first_install\n" if $opt_v;
           $portinstall_name = $first_install;
           $checker = 1;
        }
     } #### Get the <Server> name ####
     elsif ($innertag eq "Server") {
        $server = $content->[2];
        chomp($server);
        if ($checker == 1) {
          print "Server Name: $server\n" if $opt_v;
        }
     } #### Get the <PortalServerRoot> name ####
     elsif ($innertag eq "PortalServerRoot") {
        $server_root = $content->[2];
        if ($checker == 1) {
          print "Server Root: $server_root\n" if $opt_v;
        }
     } #### Get the <ExecutionID> ####
     elsif ($innertag eq "ExecutionID") {
        $executeID = $content->[2];
        if ($checker == 1) {
          print "Execution ID: $executeID\n" if $opt_v;
        }
     }
  }
  # Check if we have found the right information
  if ($checker == 1) {
    return 1;
  }else{
    return 0;
  }
}


# Get the epi_assignments.xml variables
sub getVariablesAssign {
  for (my $j=1; $j<@$elementcontent; $j+=2) {

     $innertag = $elementcontent->[$j];
     $content = $elementcontent->[$j+1];
     
     if (SkipWhiteSpace($innertag, $content)) {
        next;
     }
     print "innerelement = <$innertag>, content=<$content>\n" if $debug;     

     # for this logic to work, internal XML files must 
     # be a certain order
     if ($innertag eq "PortalInstallation") {
        my $first_install = $content->[2];
 
        if ($first_install eq $portinstall_name) {
           $assign_install = $first_install;
           print "Installation name: $assign_install\n" if $opt_v;
           $checker = 1;
        }
     } #### Get the <Portal> name ####
     elsif ($innertag eq "Portal") {
        # check if -s flag was given at command line
        if ($dash_s == 0) {
          $assign_portal = $content->[2];
          if ($checker == 1) {
            print "Portal Name: $assign_portal\n" if $opt_v;
          }
        }
     }
  }
  # Check if we have found the right information
  if ($checker == 1) {
    return 1;
  }else{
    return 0;
  }
}


# Get the epi_portalrefs.xml variables
sub getVariablesRefer {
  for (my $j=1; $j<@$elementcontent; $j+=2) {

     $innertag = $elementcontent->[$j];
     $content = $elementcontent->[$j+1];
     
     if (SkipWhiteSpace($innertag, $content)) {
        next;
     }
     print "innerelement = <$innertag>, content=<$content>\n" if $debug;     

     # for this logic to work, internal XML files must 
     # be a certain order
     if ($innertag eq "Portal") {
        my $first_ref = $content->[2];

        if ($first_ref eq $assign_portal) {
           $ref_portal = $first_ref;
           print "Portal name: $ref_portal\n" if $opt_v;
           $checker = 1;
        }
     } #### Get the <ConfigurationFile> name ####
     elsif ($innertag eq "ConfigurationFile") {
        $ref_conf_file = $content->[2];
        if ($checker == 1) {
          print "Config Filename: $ref_conf_file\n" if $opt_v;
        }
     }
  }
  # Check if we have found the right information
  if ($checker == 1) {
    return 1;
  }else{
    return 0;
  }
}


##########################################################
# SYMLINK FUNCTIONS

# compare strings, first parameter name of 
# filename in the directory
sub CompareLength_Proj_Meta  {
  my ($names) = @_;
  # check that files are metaproject_project_[mod name].pbd
  my $lm = length ($final_metaproj);
  my $lp = length ($final_proj);

  print "Meta StrLength: $lm, proj strlength: $lp\n" if $debug;
  print "NAME: $names.\n" if $debug;

  # get the characters that = metaproj
  my $meta = substr($names, 0, $lm);
  print "Meta: $meta\n" if $debug;

  # get the characters that = proj
  my $s_proj = substr($names, $lm+1, $lp);         
  print "Proj: $s_proj\n" if $debug;

  # CHECK: and see if the naming convention is followed
  if (($final_metaproj ne $meta) || ($final_proj ne $s_proj)) {
     return 0;    
  }else{
     return 1;
  }
}


# open directory and write information to it
sub OpenandWrite {
  my $names;  # variable for filename 
  my ($directory, $server_dir) = @_;
  print "Going to directory: $directory\n" if $opt_v;
  
  if (-e $directory) {  
   opendir(DIR, $directory) || die "ERROR: Couldn't read from $directory.\n";
   while ($names = readdir(DIR)) {
     print "$names\n" if $debug; 
 
     # if the function returns true then create the link
     # otherwise we don't use that file
     if (CompareLength_Proj_Meta($names)) {
        #symlink ( source file,  destination directory )
        print "Linking: $names\n" if $opt_v;
        symlink ("$directory/$names", "$server_dir/$names") || 
        print "ERROR: Couldn't link $directory/$names to $server_dir/$names\n";
     }
   }
   close(DIR);   
  }else{
   print "NOTE: Project Directory: $directory does not exist. No linking done.\n";
  }
}


# Compress the new symlink string
sub CompressString {
  my($origstring) = @_;
  my $newstring = $origstring;

  ## parse out all the _'s
  $newstring =~ s/_+//g;
  return $newstring;
}


# open directory and write information to it
sub OpenandWriteTemplate {
  my $names;  # variable for filename 
  my ($directory, $server_dir) = @_;
  print "Going to directory: $directory\n" if $opt_v;

  if (-e $directory) {  
   opendir(DIR, $directory) || die "Couldn't read from $directory.\n";
   while ($names = readdir(DIR)) {
     print "$names\n" if $debug; 
 
     # if the function returns true then create the link
     # otherwise we don't use that file
     if (CompareLength_Proj_Meta($names)) {
        #symlink ( source file,  destination directory )
        my $newname = CompressString($names);

        print "Linking original: $names\n" if $opt_v;
        print "Renamed: $newname\n" if $opt_v;
        symlink ("$directory/$names", "$server_dir/$newname") || 
        print "ERROR: Couldn't link $directory/$names to $server_dir/$newname\n";
     }
   }
   close(DIR);
 }else{
   print "NOTE: Project directory $directory does not exist. No linking done.\n";
 }   
}


#####################################################
# Link from the project directory to the PortalServer 
# project directory always changes, Server directory stays
# the same.
sub CreateSymLinks() {
   print "Creating symbolic links....\n";

   ##############################
   #PBD files: create link in PSERVERROOT for every file in ProjectRoot 
   my $server_dir = "$server_root/config/beans/defs";
   print "\nCREATING PBD LINKS................\n";

   if ($pbd_count == 0) {
     my $pbd_dir = "$proj_root/config/beans/defs";
     OpenandWrite($pbd_dir, $server_dir); 

   }else{
      # use $pbddir_optional and use array of names in @modname_pbd
      if (-e $pbddir_optional) {
         foreach $x (@modname_pbd) {
            my $newmod = $x.".pbd";
            print "Linking: $newmod\n" if $opt_v;
            if (-e "$pbddir_optional/$newmod") {
              symlink("$pbddir_optional/$newmod", "$server_dir/$newmod") ||
              print "ERROR: Couldn't link $pbddir_optional/$newmod to $server_dir/$newmod\n";
            }else{
              print "NOTE $pbddir_optional/$newmod does not exist. No linking done.\n";
            }          
         }
       }else{
         print "NOTE: $pbddir_optional does not exist. No linking done.\n";
       }
   }

   ##############################
   #CONFIG file: CHECK if ProjectRoot/config/metaproject_project.txt exists
   print "\nCREATING CONFIG LINK................\n";
   my $config_file_locate;
   my $config_file = $final_metaproj."_"."$final_proj.txt";

   if ($config_count == 0) {
     $config_file_locate = "$proj_root/config/$final_metaproj"."_"."$final_proj.txt";
   }else{
     $config_file_locate = $config_optional;
   }
   print "Config location: $config_file_locate\n" if $debug;

   if (-e  $config_file_locate) {
      # file exists so create symbolic link
      symlink($config_file_locate, "$server_root/config/$config_file") || 
      print "ERROR: Couldn't link $config_file_locate to $server_root/config/$config_file\n";
   }else{
      print "NOTE: $config_file_locate does not exist. No linking done.\n";
   }

   ##############################
   #JAR file: Check if optional specified, check file exists.
   print "\nCREATING JARFILE LINK................\n";
   my $jar_file_locate;
   my $jar_file = $final_metaproj."_"."$final_proj.jar";

   if ($jar_count == 0) {
     $jar_file_locate = "$proj_root/lib/$final_metaproj"."_"."$final_proj.jar";
     print "Jar File: $jar_file_locate\n";

     if (-e $jar_file_locate) {
        # create the link, file exists
        print "Linking jarfile: $jar_file_locate to $server_root/lib/$jar_file\n" if $opt_v;
        symlink($jar_file_locate, "$server_root/lib/$jar_file") || 
        print "ERROR: Couldn't link $jar_file_locate to $server_root/lib/$jar_file\n";
     }else{
        print "NOTE: $jar_file_locate does not exist. No linking done.\n";
     }
   }else{
     $jar_file_locate = $jar_dir;
     print "Jar File: $jar_file_locate\n";

     if (-e $jar_file_locate) { 
        foreach $x (@jar_files) {
          if (-e "$jar_file_locate/$x") {
             print "Linking jarfile: $jar_file_locate/$x to $server_root/lib/$x\n" if $opt_v;
             symlink("$jar_file_locate/$x", "$server_root/lib/$x") || 
             print "ERROR: Couldn't link $jar_file/$x to $server_root/lib/$x\n";
          }else{
             print "NOTE: $jar_file_locate/$x does not exist. No linking done.\n";
          } 
        }
     }else{
        print "NOTE: $jar_file_locate does not exist. No linking done.\n";
     }

   }

   ##############################
   #PRESENTATION file: 
   print "\nCREATING PRESENTATION LINKS............\n";
   $server_dir = "$server_root/msdw_portal/beans";
   my $pres_file_proj;

   ## Check if optional tags were specified
   if ($bean_count == 0) {   
      $pres_file_proj = "$proj_root/msdw_portal/beans";
   }else{
      $pres_file_proj = $beandir_root;
   }
    
   OpenandWrite($pres_file_proj, $server_dir);

   ##############################
   #IMAGES files:
   my $image_file_proj = "$proj_root/msdw_portal/images/$final_metaproj"."_"."$final_proj/";
   my $image_file = $final_metaproj."_".$final_proj;
    
   print "\nCREATING IMAGES DIRECTORY LINK................\n";
   print "IMAGE directory: $image_file_proj\n" if $opt_v;
   
   if (-d $image_file_proj) {
      # create the directory link
      symlink($image_file_proj, "$server_root/msdw_portal/images/$image_file") ||
      print "ERROR: Couldn't link $image_file_proj to $server_root/msdw_portal/images/$image_file\n";      
   }else{
      print "NOTE: $image_file_proj does not exist. No linking done.\n";
   }

   ###############################
   #CHROME templates:
   $server_dir = "$server_root/msdw_portal/templates/chrome1";
   print "\nCREATING CHROME DIRECTORY LINK................\n";
   my $chrome_proj;

   if ($chrome_count == 0) {
      $chrome_proj = "$proj_root/msdw_portal/templates/chrome1";
      OpenandWriteTemplate($chrome_proj, $server_dir);

   }else{
      $chrome_proj = $chrome_option;
      foreach $x (@chrome_dir) {
        if (-e "$chrome_proj/$x") {
           my $chrome_name = CompressString($x);     
           print "Linking: $chrome_proj/$x to $server_dir/$chrome_name\n" if $opt_v;
           symlink("$chrome_proj/$x", "$server_dir/$chrome_name") || 
           print "ERROR: Couldn't link $chrome_proj/$x to $server_dir/$chrome_name\n";

        }else{
           print "NOTE: $chrome_proj/$x does not exist. No linking done.\n";
        }
      }      
   }    

   ###############################
   #FOOTER templates:
   $server_dir = "$server_root/msdw_portal/templates/footer1";
   print "\nCREATING FOOTER DIRECTORY LINK................\n";
   my $footer_proj;
   if ($foot_count == 0) {
      $footer_proj = "$proj_root/msdw_portal/templates/footer1";
      OpenandWriteTemplate($footer_proj, $server_dir);

   }else{
      $footer_proj = $footer_option;
      foreach $x (@footer_dir) {
        if (-e "$footer_proj/$x") {
           my $footer_name = CompressString($x);     
           print "Linking: $footer_proj/$x to $server_dir/$footer_name\n" if $opt_v;
           symlink("$footer_proj/$x", "$server_dir/$footer_name") || 
           print "ERROR: Couldn't link $footer_proj/$x to $server_dir/$footer_name\n";

        }else{
           print "NOTE: $footer_proj/$x does not exist. No linking done.\n";
        }
      }      
   }
   ###############################
   #HEADER templates:
   $server_dir = "$server_root/msdw_portal/templates/header1";
   print "\nCREATING HEADER DIRECTORY LINK................\n";
   my $header_proj;
   if ($head_count == 0) {
      $header_proj = "$proj_root/msdw_portal/templates/header1";
      OpenandWriteTemplate($header_proj, $server_dir);

   }else{
      $header_proj = $header_option;
      foreach $x (@header_dir) {
        if (-e "$header_proj/$x") {
           my $header_name = CompressString($x);     
           print "Linking: $header_proj/$x to $server_dir/$header_name\n" if $opt_v;
           symlink("$header_proj/$x", "$server_dir/$header_name") || 
           print "ERROR: Couldn't link $header_proj/$x to $server_dir/$header_name\n";

        }else{
           print "NOTE: $header_proj/$x does not exist. No linking done.\n";
        }
      }      
   }
   ###############################
   #INDEX templates:
   $server_dir = "$server_root/msdw_portal/templates/index1";
   print "\nCREATING INDEX DIRECTORY LINK................\n";
   my $index_proj;
   if ($index_count == 0) {
     $index_proj = "$proj_root/msdw_portal/templates/index1";
      OpenandWriteTemplate($index_proj, $server_dir);

   }else{
      $index_proj = $index_option;
      foreach $x (@index_dir) {
        if (-e "$index_proj/$x") {
           my $index_name = CompressString($x);     
           print "Linking: $index_proj/$x to $server_dir/$index_name\n" if $opt_v;
           symlink("$index_proj/$x", "$server_dir/$index_name") || 
           print "ERROR: Couldn't link $index_proj/$x to $server_dir/$index_name\n";

        }else{
           print "NOTE: $index_proj/$x does not exist. No linking done.\n";
        }
      }      
   }
   ###############################
   #NAV templates:
   $server_dir = "$server_root/msdw_portal/templates/nav1";
   print "\nCREATING NAV DIRECTORY LINK................\n";
   my $nav_proj;
   if ($nav_count == 0) {
      $nav_proj = "$proj_root/msdw_portal/templates/nav1";
      OpenandWriteTemplate($nav_proj, $server_dir);

   }else{
      $nav_proj = $nav_option;
      foreach $x (@nav_dir) {
        if (-e "$nav_proj/$x") {
           my $nav_name = CompressString($x);     
           print "Linking: $nav_proj/$x to $server_dir/$nav_name\n" if $opt_v;
           symlink("$nav_proj/$x", "$server_dir/$nav_name") || 
           print "ERROR: Couldn't link $nav_proj/$x to $server_dir/$nav_name\n";

        }else{
           print "NOTE: $nav_proj/$x does not exist. No linking done.\n";
        }
      }      
   }
   ###############################
   #TAB templates:
   $server_dir = "$server_root/msdw_portal/templates/tab1";
   print "\nCREATING TAB DIRECTORY LINK................\n";
   my $tab_proj;
   if ($tab_count == 0) {
      $tab_proj = "$proj_root/msdw_portal/templates/tab1";
      OpenandWriteTemplate($tab_proj, $server_dir);

   }else{
      $tab_proj = $tab_option;
      foreach $x (@tab_dir) {
        if (-e "$tab_proj/$x") {
           my $tab_name = CompressString($x);     
           print "Linking: $tab_proj/$x to $server_dir/$tab_name\n" if $opt_v;
           symlink("$tab_proj/$x", "$server_dir/$tab_name") || 
           print "ERROR: Couldn't link $tab_proj/$x to $server_dir/$tab_name\n";

        }else{
           print "NOTE: $tab_proj/$x does not exist. No linking done.\n";
        }
      }      
   }
}


###############################################################

sub OpenandDeleteOrPrint {
  my ($directory) = @_;

  if (-e $directory) {
    opendir (DIR, $directory) || die "ERROR: Couldn't read from $directory.\n";
    while ($name = readdir(DIR)) {
        print "DIR IN OpenandDeletePrint: $name\n" if $debug;
        if (CompareLength_Proj_Meta($name)) {
          if ($opt_d) {
            print "Deleting $name\n" if $opt_v;
            unlink("$directory/$name") || print "ERROR: Couldn't delete $name from $directory.\n";
          }elsif ($opt_print) {
            print "Links in $directory: $name\n";
          }
        }
    }
    if ($opt_print) {
      print "Finished printing relevant contents of $directory\n";
    }elsif ($opt_d) {
      print "Finished deleting relevant contents of $directory\n";
    }         
  }else{
    if ($opt_d) {
      print "NOTE: $directory does not exist. Deletion cancelled.\n";
    }elsif ($opt_print) {
      print "NOTE: $directory does not exist.\n";
    }      
  }
}


# used for templates and FOR DELETION and PRINTING only
# to compare the compressed string with the original string
sub CompareLength_Proj_MetaTemplate  {
  my ($names) = @_;
  # check that files are metaproject_project_[mod name].pbd

  my $tempmeta = $final_metaproj;
  $tempmeta =~ s/_+//g;
  my $tempproj = $final_proj;
  $tempproj =~ s/_+//g;

  my $lm = length ($tempmeta);
  my $lp = length ($tempproj);

  print "tempmeta: $tempmeta\n" if $debug;
  print "tempproj: $tempproj\n" if $debug;
  print "Meta StrLength: $lm, proj strlength: $lp\n" if $debug;
  print "NAME: $names\n" if $debug;  

  # get the characters that = metaproj
  my $meta = substr($names, 0, $lm);
  print "Meta: $meta\n" if $debug;

  # get the characters that = proj
  my $s_proj = substr($names, $lm, $lp);
  print "Proj: $s_proj\n" if $debug;
   
  # CHECK: and see if the naming convention is followed
  if (($tempmeta ne $meta) || ($tempproj ne $s_proj)) {
     return 0;    
  }else{
     return 1;
  }
}


sub OpenandDeleteTemplateOrPrint {
  my ($directory) = @_;

  if (-e $directory) {
    opendir (DIR, $directory) || die "ERROR: Couldn't read from $directory.\n";
    while ($name = readdir(DIR)) {
        if (CompareLength_Proj_MetaTemplate($name)) {
            if ($opt_d) {
              print "Deleting $name\n" if $opt_v;
              unlink("$directory/$name") || print "ERROR: Couldn't delete $name from $directory.\n";
            }elsif ($opt_print) {
              print "Links in $directory: $name.\n";
            }
        }
    }    
    if ($opt_print) {
      print "Finished printing relevant contents of $directory\n";
    }elsif ($opt_d) {
      print "Finished deleting relevant contents of $directory\n";
    }         
  }else{
    if ($opt_d) {
      print "NOTE: $directory does not exist. Deletion cancelled.\n";
    }elsif ($opt_print) {
      print "NOTE: $directory does not exist.\n";
    }
  }
}


# Delete all the optional links
# 1st parameter server directory, 2nd parameter file name arrays
sub DeleteOptional {
   ($server_dir, @file_names) = @_;
   foreach $x (@file_names) {
      if (-e "$server_dir/$x") {
        print "Deleting: $server_dir/$x\n" if $opt_v;
        unlink ("$server_dir/$x") || print "ERROR: Couldn't delete $server_dir/$x\n";
 
      }else{
        print "NOTE: $server_dir/$x does not exist. No deletion done.\n";
      }
   }
}


sub DeleteSymLinks() {
   print "Deleting symbolic links....\n";

   # Goto PORTALSERVERROOT and delete files
   # use unlink to remove files
   ########################################
   # PBD files
   print "\nDELETING PBD LINKS.....................\n";
      
   my $pbd_server = "$server_root/config/beans/defs";
   OpenandDeleteOrPrint($pbd_server);  

   ####################
   # CONFIG File
   my $config_serverfile = "$server_root/config/$final_metaproj"."_"."$final_proj.txt";
   print "\nDELETING CONFIG FILE.....................\n";
   if (-l $config_serverfile) {
      unlink($config_serverfile) || print "ERROR: Couldn't delete $config_serverfile.\n";
   }else{
      print "NOTE: $config_serverfile does not exist. Deletion cancelled.\n";
   }        
 
   ####################
   # JAR File
   my $jar_serverfile;
   $jar_serverfile = "$server_root/lib/$final_metaproj"."_"."$final_proj.jar";
   print "\nDELETING JAR FILE.....................\n";
   if (-l $jar_serverfile) {
      unlink ($jar_serverfile) || print "ERROR: Couldn't delete $jar_serverfile.\n";
   }else{
      print "NOTE: $jar_serverfile does not exist. Deletion cancelled.\n";
   }
   #Delete everything in optional
   if ($jar_count > 0) {
      my $jar_serverdir = "$server_root/lib";
      DeleteOptional($jar_serverdir, @jar_files); 
   }

   ####################
   # Presentation Files
   my $pres_server = "$server_root/msdw_portal/beans";
   print "\nDELETING PRESENTATION FILES..................\n";
   OpenandDeleteOrPrint($pres_server);

   #delete optional PBD's if any
   if ($pbd_count > 0) {
      DeleteOptional($pres_server, @modname_pbd);
   }

   ####################
   # Image directory
   my $image_server = "$server_root/msdw_portal/images/$final_metaproj"."_".$final_proj;
   print "\nDELETING IMAGE DIRECTORIES.....................\n";
   if (-l $image_server) {
      unlink($image_server) || print "ERROR: Couldn't delete $image_server.\n";
   }else{
      print "NOTE: $image_server does not exist. Deletion cancelled.\n";
   }

   ####################
   # Chrome templates
   my $template_server = "$server_root/msdw_portal/templates/chrome1";
   print "\nDELETING CHROME TEMPLATES.....................\n";

   OpenandDeleteTemplateOrPrint($template_server);
   
   # delete optional links if any
   if ($chrome_count > 0) {
      DeleteOptional($template_server, @chrome_dir);
   }

   ####################
   # Footer templates
   my $footer_server = "$server_root/msdw_portal/templates/footer1";
   print "\nDELETING FOOTER TEMPLATES.....................\n";
   OpenandDeleteTemplateOrPrint($footer_server);

   # delete optional if any
   if ($foot_count > 0) {
      DeleteOptional($footer_server, @footer_dir);
   }   

   ####################
   # Header templates
   my $header_server = "$server_root/msdw_portal/templates/header1";
   print "\nDELETING HEADER TEMPLATES.....................\n";
   OpenandDeleteTemplateOrPrint($header_server);

   # delete optional if any
   if ($head_count > 0) {
      DeleteOptional($header_server, @header_dir);
   }

   ####################
   # Index templates
   my $index_server = "$server_root/msdw_portal/templates/index1";
   print "\nDELETING INDEX TEMPLATES.....................\n";
   OpenandDeleteTemplateOrPrint($index_server);
 
   # delete optional if any
   if ($index_count > 0) {
      DeleteOptional($index_server, @index_dir);
   }

   ####################
   # Nav templates
   my $nav_server = "$server_root/msdw_portal/templates/nav1";
   print "\nDELETING NAV TEMPLATES.....................\n";
   OpenandDeleteTemplateOrPrint($nav_server);

   # delete optional if any
   if ($nav_count > 0) {
      DeleteOptional($nav_server, @nav_dir);
   }

   ####################
   # Tab templates
   my $tab_server = "$server_root/msdw_portal/templates/tab1";
   print "\nDELETING TAB TEMPLATES.....................\n";
   OpenandDeleteTemplateOrPrint($tab_server);

   # delete optional if any
   if ($tab_count > 0) {
      DeleteOptional($tab_server, @tab_dir);
   }

}


#######################################################
# for printing links only
sub PrintOut() {
   print "Printing out links....\n";
   print "......................\n";

   #PBD files
   my $pbd_server = "$server_root/config/beans/defs";
   OpenandDeleteOrPrint($pbd_server);

   #Config file
   my $config_location = "$server_root/config/$final_metaproj"."_"."$final_proj.txt";         
   if (-l $config_location) {
      print "Config file link: $config_location.\n";
   }else{
      print "NOTE: $config_location does not exist.\n";
   }

   #Jar File
   my $jar_location = "$server_root/lib/$final_metaproj"."_"."$final_proj.jar";
   if (-l $jar_location) {
      print "Jar file link: $jar_location.\n";
   }else{
      print "NOTE: $jar_location does not exist.\n";
   }
      
   #Presentation Files
   my $pres_location = "$server_root/msdw_portal/beans";
   OpenandDeleteOrPrint($pres_location);   
  
   #Images Directory
   my $image_dir = "$server_root/msdw_portal/images/$final_metaproj"."_".$final_proj;
   if (-l $image_dir) {
      print "Images directory: $image_dir.\n";
   }else{
      print "NOTE: $image_dir does not exist.\n";
   }

   #Chrome Templates
   my $chrome_server = "$server_root/msdw_portal/templates/chrome1";
   OpenandDeleteTemplateOrPrint($chrome_server);   
     
   #Footer Templates
   my $footer_server = "$server_root/msdw_portal/templates/footer1";
   OpenandDeleteTemplateOrPrint($footer_server);   

   #Header Templates
   my $header_server = "$server_root/msdw_portal/templates/header1";
   OpenandDeleteTemplateOrPrint($header_server);   

   #Index Templates
   my $index_server = "$server_root/msdw_portal/templates/index1";
   OpenandDeleteTemplateOrPrint($index_server);   

   #Nav Templates
   my $nav_server = "$server_root/msdw_portal/templates/nav1";
   OpenandDeleteTemplateOrPrint($nav_server);   

   #Tab Templates
   my $tab_server = "$server_root/msdw_portal/templates/tab1";
   OpenandDeleteTemplateOrPrint($tab_server);   

}

