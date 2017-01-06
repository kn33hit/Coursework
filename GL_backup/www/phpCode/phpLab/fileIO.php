<?php 
function findKeyword($word){

$myfile = fopen("FILEIOLabDATAFILE.txt", "r") or die("Unable to open file!");
$count = 1;
while(!feof($myfile)){
  
  $line = fgets($myfile);
  if (strpos($line, $word) !== false) {
    return $count;
  }
  
  $count += 1;
}

fclose($myfile);
}

function filter(){
  $myfile = fopen("FILEIOLabDATAFILE.txt", "r") or die("Unable to open file!");
  $avoid = array("the","to","that","and");
  while(!feof($myfile)){
    $line = fgets($myfile);
    $nLine= str_replace($avoid,"", $line);
    echo $nLine."<br>";
    
  }
  fclose($myfile);

}

// echo "line number: " . findKeyword("explosive");
filter();
?>