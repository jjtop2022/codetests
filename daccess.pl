#!/ms/dist/aurora/bin/perl

####################################################
# 1. parseout HTML file contents
# testing the parser and pipe to a file
# >parseme.pl inter.html > testfile.txt

# 2. insert content of text file into the database 
# this command will login on to the specified
# database through the command line.
# >fsql -U yiujim -P yiujim -D jimtest1 -S NYT_JIM_TEST1

####################################################
# This script will take an argument parameter which
# is a text file and will take the fields and update a
# database which will most likely be hard-coded.

use Cwd;
use Sybase::DBlib;

####################################################
# Read in file contents from command line
# 1. The text file first, then 
# 2. the SQL commands file.

@ARGV == 2 or die "Enter the text file, then the SQL file.\n";

($Text, $SQLpage) = @ARGV;

open (TEXT, "< $Text") or die "Cannot open $Text\n";

print "\n------------------------------------------------\n";
print "First file is the input TEXT file, second file\n";
print "is the SQL command file.\n";

#####################################################
#system ("fsql -U yiujim -P yiujim -D jimtest1 -S NYT_JIM_TEST1 < $SQLpage;") == 0
#       or die "Couldn't connect to database!\n";

# reading in text file into array
@line = <TEXT>;


$IDbuffer = "";
$contentbuffer = "";

$dir = cwd();
print "current working directory is: $dir\n";

foreach $singleline (@line) {

     if ( $singleline =~ m/%+/i ){
        
        #---------- parse out the %'s -----------
        $singleline =~ s/%+//;
        $singleline =~ s/%+//;
           # $singleline =~ tr/a-z/A-Z/;
        print "title: $singleline";
	$IDbuffer = $singleline;
        
     }else {
        print "$singleline";
        $contentbuffer = $singleline;
     }

}


# remove newline characters
chomp ($IDbuffer);
chomp ($contentbuffer);

# call the subroutines
SQLInit();
Showrecord();
Insertrecord($IDbuffer, $contentbuffer);


#############################
# Initialize database routine
sub SQLInit
{

	$dbaccess = Sybase::DBlib->dblogin("yiujim", "yiujim", "NYT_JIM_TEST1");
	$dbaccess != -1 || die "Cannot connect to server!";
	$dbaccess->dbuse("jimtest1") || die "Cannot connect to database!\n";

}


sub Showrecord
{

	$sqlStr = "SELECT * FROM epractice_test";

	$dbaccess->dbcmd($sqlStr) || die "Error in query";
	$dbaccess->dbsqlexec || die "Error in execution";
	$dbaccess->dbresults;

        while (%data = $dbaccess->dbnextrow(1)) 
	{
         $datacount += 1;
         $title = $data{"title"};
         $contents = $data{"table_contents"};
        }

	print "Count=$datacount\n";
	print "ID=$ID\n";
	print "Title=$title\n";
	print "Contents=$contents\n";

}


sub Insertrecord
{

        my ($tablebuffer1, $contentbuffer1) = @_;
	$sqlInsert = "INSERT into epractice_test (title, table_contents)
                  values (\"$tablebuffer1\", \"$contentbuffer1\")";
 
	$dbaccess->dbcmd($sqlInsert) || die "Error in query";
	$dbaccess->dbsqlexec || die "Error in execution";
	$dbaccess->dbresults;
	print "Records inserted.\n";

}

