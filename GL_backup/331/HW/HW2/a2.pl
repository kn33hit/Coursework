#!/usr/bin/perl
use warnings;
use POSIX;
use 5.10.1;

#Names: Melissa Thai
#   Neh Patel
#   Kate Swanson
#   Dong Sun
#CMSC 331 - Section 04
#Assignment 2


sub readWords {
    #Filename Validation and Re-prompt
    print "\n Type 'quit' to end program. Enter the name of the text file: ";
    my $filename = <>;

    #clears whitespace
    chomp($filename);

    if ($filename eq "quit"){
	exit 0;
    }

    #opens file based on filename, kill programs if not found
    open (my $infile, "<", $filename) or die "Cannot open file"; #MT: changed "<words.txt" to $filename


    #Declare list used to store data elements
    my @data;
    
    #Read file data into string array 'data'
    while (my $line = <$infile>){
	push(@data, split(" ", $line));
    }

    close($infile);
    return @data;
}


#ONLY CRITERIA LEFT! Do not change code within doc up here; paste at bottom so we know any changes being made!
sub crit1{
 
    #reading parameter sent in and storing in $string
    my $string = $_[0];

#print("Code: " , ord(substr($string,0,1)),"\n");

    utf8::encode($string);
    if(substr($string,0,1) =~ /\p{IsGreek}/){
	print ("GREEK! " , $string);
    }

}


sub crit2{

    my $string = $_[0];
    my $count = 0;

    my $open_bracket = 0;
    my $closed_bracket = 0;


    #goes through each character of string to check for brackets
    for($i = 0; $i < length($string); $i++){
	my $current = substr($string,$i,1);
    
	if($current eq "["){
	    $open_bracket++;
	}
	elsif($current eq "]"){
	    $closed_bracket++;
	}
    }

    #if there is balanced set of [] then it is true
    if ($open_bracket == $closed_bracket && $open_bracket != 0){
	return 1;
    }
    else{
	return 0;
    }
}

sub crit3{

    my $string = $_[0];
    my $current;
    my $next;

    for($i = 0; $i < length($string) - 1; $i++){
	$current = substr($string, $i, 1);
	$next = substr($string, $i+1, 1);

	if ($current eq $next && $current =~ /[a-zA-Z]/){
	    if ($i+3 <= length($string)) {
		if(substr($string, $i+2, 1) eq substr($string, $i+3, 1) && substr($string, $i+2, 1) =~ /[a-zA-Z]/) {
		    return 1;
		}
	    } else {
		return 0;
	    }

	}
    }
    return 0; #return false
}

#CRIT 4 WORKS. YAY - Melissa
sub crit4 {
    my @arr = @_;
    my $freq = 0;
    my $num = -999999999999999999999999999;

    for ($m = 0; $m <= $#arr; $m++) {
    #checks if its a number, and it must be larger than the
    #previously stored number
	if($arr[$m] =~ /^\d+$/ && $arr[$m] > $num) {
	    #replaces it to be the next biggest num
	    $num = $arr[$m];
	    $freq++;
	}
    }
    if ($freq != 0){
	$freq--;
    }
    return $freq;
}


#CRIT 5 WORKS. - Melissa
sub crit5{
    my $string = $_[0];
    my $current = 0;
    my $next = 0;
    my $count = 0;

    #Checks if every character of the datum/string is the same
    for($i = 0; $i < length($string)-1; $i++){
	$current = substr($string, $i, 1);
	$next = substr($string, $i+1, 1);
	if ($current ne $next){

	    return 0;
	}
	$count++;
    }
    $count++;

    #if $count is less than 2, it is not prime.
    if ($count < 2){

	return 0;
    }

    #checks for prime
    for ($k = ceil($count**0.5); $k >= 2; $k--){
	if ($count%$k == 0 && $count != $k){
	    return 0;
	}
    }

    return 1;
}


sub main(){
    print "Assignment 2\n";
    print "Authors: Katie, Neh, Melissa, Dong\n";
    
    #Declare lists
    my @inputData;
    my @outputData;


    #Read in the textfile
    @inputData = readWords();

    my $crit1_count = 0;
    my $crit2_count = 0;
    my $crit3_count = 0;
    my $crit4_count = 0;
    my $crit5_count = 0;
    my $size = 0;
    $size = scalar (@inputData);

    my $l = 0;
    for ($l = 0; $l < $size; $l++){
	if(crit1($inputData[$l])){
	    $crit1_count++;
	}
	if(crit2($inputData[$l])){
	    $crit2_count++;
	}
	if(crit3($inputData[$l])){
	    $crit3_count++;
	}
	if(crit5($inputData[$l])){
	    $crit5_count++;
	}

    }
    $crit4_count = crit4(@inputData);


#Sorting the counts using dict
    my %dict = ("\nStarts with Greek, end with Cyrillic: " => $crit1_count, "\nContains balance brackets: " => $crit2_count, "\nHas distinct double letters in a row: " => $crit3_count, "\nBiggest-yet integers: " => $crit4_count, "\nCharacter repeated a prime number of times: " => $crit5_count);
    

    foreach my$name(sort{$dict{$a} <=> $dict{$b}}keys %dict){
	print($name, $dict{$name});
    }
    print("\n");
}

main();

