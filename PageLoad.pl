#!/usr/bin/perl

################################################
# **This script will determine the pageloads/sec from
# the output of wget and will utilize the 2nd string
# in the output which is the Time Elasped since 
# January 01, 1970. It will then take the 5th string
# which is Total Time and add them together to form
# a End Time for each line of output for wget.
# **It will then take all these times and bucket them
# according to each second, the highest count will be
# the maximum page loads / sec.
################################################
# The input is a file containing wget output

use Number::Format qw(:subs);
use Time::localtime;
use Getopt::Std;

my @line = ();      # buffer for reading file contents
my @start_time =(); # start time for results
my @end_time =();   # end time for results
my @results =();    # holds the end time results
my @numholder=();   # holds all final numbers
my @b_holder=();    # holds final bucketed numbers
my %bucketed = ();  # bucketed times into categories
my $i=0;
my $total;
my $avgload;

getopts("v");

@ARGV == 1 or die "Enter the input file of wget";

my ($inputfile) = @ARGV;
open (WFILE, "< $inputfile") or die "Cannot open $inputfile\n";

#read contents into array
@line = <WFILE>;

foreach $x (@line) {
   #get the required variables 2nd token and 5th token
   GetTokens($x);
}

#add both times and put into @results
foreach $x (@start_time) {
   my $end_result;
   # call the other @end_time buffer  
   my $temp = PushSingle($i);
   $end_result = $temp + $x;
   push (@results, $end_result);
   $i++;
}

#round to an even integer
foreach $x (@results) {
   $newnum = round($x, 0);
   #push rounded values onto new array
   push (@numholder, $newnum);
}

#bucket the results for each second
#time is in Epoch Time,format in seconds
foreach $x (@numholder) {
   #Bucket into categories
   BucketIt($x);
}

#put into hash
foreach $x (@b_holder) {
   $bucketed{$x} = 0;
}

#Now use both @numholder and @b_holder to
#find out number of repeats for each time:
#this will lead to page loads / second.
foreach $x (@numholder) {
   #check hash and increment for repeat times
   $bucketed{$x} = $bucketed{$x} + 1;        
}


#### PRINTING INFO ####
$i=0;
$total = 0;
$last=-1;
$max=0;

#sort by time
foreach $x (sort keys %bucketed) {

   #used for factoring in 0 hits
   if ($last>0) {
      for ($k=$last+1; $k<$x; $k++) {
         print "$i Epoch Time: $k ";
         $newtime = CorrectTime($k);
         PrintTime($newtime);  
         print "*Number of page loads: 0\n";
         $i++;
      }
   }
   print "$i Epoch Time: $x ";
   $newtime = CorrectTime($x);
   PrintTime($newtime);  
   $total = $total + $bucketed{$x};
   print "*Number of page loads: $bucketed{$x}\n";
   $i++;
   $last = $x;

   if ($bucketed{$x}>$max) {
      $max = $bucketed{$x};
   }
}

# Get Avg. Pageloads /sec.
$avgload = $total / $i;
print "********************************\n";
print "Total count: $i\n";
print "Average PageLoads per second: $avgload\n";
print "Max PageLoads per second: $max\n";


############DEBUG INFO#############
#$i=0;
#foreach $x (@numholder) {
#   print "$i EPOCH Time: $x ";
#   $newtime = CorrectTime($x);
#   PrintTime($newtime);print "\n";      
#   $i++;
#}
#$i =0;
#foreach $x (@b_holder) {
#   print "Bucketed $i $x\n";
#   $i++;
#}
###################################


################################################
sub GetTokens () {
   my ($line) = @_;
   my $epo_time = 900000000;

   # make sure we have the real wget output
   # get the 2nd and 6th token in the output
   @newline = split(/ /, $line);
   my $tok = @newline;  #get the number of tokens
   my $epo_check = $newline[1];

   # use -v to make sure we get the right lines
   print "CHECK: $epo_check, $epo_time, TOK: $tok\n" if $opt_v;
   if ($tok == 14 || $epo_check > $epo_time) {
       push (@start_time, $newline[1]);
       push (@end_time,  $newline[6]);
       print "NEWLINE: @newline, 1st: $newline[1], 2nd: $newline[6]\n" if $opt_v;
   }
}

#push unique values onto @b_holder array
sub BucketIt () {
   my ($inputtoken) = @_;
   if (CheckSingle($inputtoken) != 1) {   
      push (@b_holder, $inputtoken);
   }
}

# return 1 if input variable matchs 
# something in the array, return 0 if no match
sub CheckSingle () {
   my ($tempchecker) = @_; 
   chomp($tempchecker);

   # initial check to see if b_holder is empty
   my $firstcheck = @b_holder; 
   if ($firstcheck == 0) {
      push (@b_holder, $tempchecker);
      return 1;
   }else{
      #loop through array and find repeats of the same number
      foreach $n (@b_holder) {
        chomp($n);
        if ($n =~ m/$tempchecker/) {
           return 1;
           last;
        }
      }
      return 0;
   }
}

sub PushSingle () {
   my ($k) = @_;
   return $end_time[$k];
}

sub CorrectTime () {
   my ($epo_time) = @_;
   $tm = localtime($epo_time);
   return $tm;
}

sub PrintTime () {
   my ($newtime) = @_;
   printf ("Formatted Time: %02d:%02d:%02d %02d/%02d/%04d ", 
   $newtime->hour, $newtime->min, $newtime->sec, 
   $newtime->mon+1, $newtime->mday, $newtime->year+1900);  
}

