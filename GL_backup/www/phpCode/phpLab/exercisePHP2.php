<?php 

$GPA = array("student1"=>"","student2"=>"","student3"=>"");

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $GPA[student1] = test_input($_POST["GPA1"]);
  $GPA[student2] = test_input($_POST["GPA2"]);
  $GPA[student3] = test_input($_POST["GPA3"]);
 
}
function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

$var1 = 0;
$total = 0;

asort($GPA);
foreach($GPA as $x => $x_val) {
  if($var1 == 0){
    echo("The minimum GPA is: " . $x_val . "<br>"); 
  }
  $var1 += 1;
  $total += $x_val;
  if($var1 == 3){
    echo("The maximum GPA is: " . $x_val . "<br>");
  }
}

$average = $total / $var1;

echo("Total count is: " . $var1 . "<br>");
echo("Average GPA is: " . $average);

?>