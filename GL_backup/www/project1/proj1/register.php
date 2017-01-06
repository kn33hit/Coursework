<?php

if ($_SERVER['HTTP_REFERER'] == ""){
	header("location: index.php");
	die();
}

?>


<!DOCTYPE html>
<html>
<title>UMBC | CMSC Advising</title>
<head>
<link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>

<?php
// Initialize variables to null.
$ID = $name = $email = $phone ="";
$classErr = array();
$class = array();
$validClass = array();

# SQL INFO 
$dbhost = 'studentdb-maria.gl.umbc.edu';
$dbuser = 'npatel10';
$dbpass = 'npatel10';
$dbName = 'npatel10';

if ($_SERVER["REQUEST_METHOD"] == "POST") {

	$ID = test_input($_POST["ID"]);
	$name = test_input($_POST["name"]);
	$email = test_input($_POST["email"]);
	$phone = test_input($_POST["phone"]);
	$validClass = unserialize($_POST["suggestClass"]);
	
	if (empty($_POST["class1"])) {
		
	} else {
		$class[0] = test_input($_POST["class1"]);
		if (!preg_match("/^[A-Z]{4}\d{3}$/",$class[0])) {
			$classErr[0] = "Error: Invalid class ID format<br>";
		} 
		if(!in_array($class[0], $validClass)){
			$classErr[0].= "Error: This class is not available for you, please pick a suggested class<br>";

		}
	}

	if (empty($_POST["class2"])) {
		
	} else {
		$class[1] = test_input($_POST["class2"]);
		if (!preg_match("/^[A-Z]{4}\d{3}$/",$class[1])) {
			$classErr[1] = "Error: Invalid class ID format<br>";
		} 
		if ($class[1] == $class[0]){
			$classErr[1].= "Error: same class repeated, please try another class<br>";
		}
                  if(!in_array($class[1], $validClass)){
			$classErr[1].= "Error: This class is not available for you, please pick a suggested class<br>";

		}
	}

	if (empty($_POST["class3"])) {
		
	} else {
		$class[2] = test_input($_POST["class3"]);
		if (!preg_match("/^[A-Z]{4}\d{3}$/",$class[2])) {
			$classErr[2] = "Error: Invalid class ID format<br>";
		} 
		if ($class[2] == $class[0] or $class[2] == $class[1] ){
			$classErr[2].= "Error: same class repeated, please try another class<br>";
		}
		if(!in_array($class[2], $validClass)){
			$classErr[2].= "Error: This class is not available for you, please pick a suggested class<br>";

		}
	}

	if (empty($_POST["class4"])) {
		
	} else {
		$class[3] = test_input($_POST["class4"]);
		if (!preg_match("/^[A-Z]{4}\d{3}$/",$class[3])) {
			$classErr[3] = "Error: Invalid class ID format<br>";
		}
		if ($class[3] == $class[0] or $class[3] == $class[1] or $class[3] == $class[2] ){
			$classErr[3].= "Error: same class repeated, please try another class<br>";
			
		}
		if(!in_array($class[3], $validClass)){
			$classErr[3].= "Error: This class is not available for you, please pick a suggested class<br>";

		}
	}

	if (empty($_POST["class5"])) {
		
	} else {
		$class[4] = test_input($_POST["class5"]);
		if (!preg_match("/^[A-Z]{4}[\s]?\d{3}$/",$class[4])) {
			$classErr[4] = "Error: Invalid class ID format<br>";
		}
		if ($class[4] == $class[0] or $class[4] == $class[1] or $class[4] == $class[2] or $class[4] == $class[3]){
			$classErr[4].= "Error: same class repeated, please try another class<br>";
		}		
		if(!in_array($class[4], $validClass)){
			$classErr[4].= "Error: This class is not available for you, please pick a suggested class<br>";

		}
	}


}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

?>

<!-- The "topTitle" div -->
<!-- Has one span in it to highlght the "UMBC" red in title -->
<div class = "topTitle">
  <h1> <span style = "color:red"> UMBC </span> Advising for Computer Science Majors </h1> 
</div>

<!-- NAVIGATION BAR(LEFT-SIDE) with three things: Home, List of Classes, and About tab --> 
<!-- Currently it all the options link to the same html file -->
<ul>
  <li><a href="index.php">Home</a></li>
  <li><a class="active">Confirmation</a></li>
  <li><a href="contact.html">Contact</a></li>
</ul>

<!-- MAIN DIV -->
<!--The main div to put the form in, which will take in all the information--> 
<div class = "mainDiv">

<?php
$Color = "red";
echo "<h2>Personal Information:</h2>";
echo "Student ID: ". $ID."<br>\n";
echo "Name: ". $name."<br>\n";
echo "Email: ". $email."<br>\n";
echo "Phone Number: ". $phone."<br>\n";

echo "<h2>Class Regiestered Information:</h2>";
$arrlength = count($class);

if($arrlength == 0) {
	echo "You didn't register any class, please fill in the class you want to take.<br><br>\n";
?>
	<form><input Type="button" value="Back" onClick="history.go(-1);return true;"></form>
<?php } else {
	for($x = 0; $x < $arrlength; $x++) {
	  $count = $x + 1;
  	  echo "Class ". $count. " Input: " . $class[$x];
	  echo '<p style="Color:'.$Color.'">'.$classErr[$x].'</p>';
   	  
	}
}

if(empty($classErr) and !empty($class)) {
	# SQL CODE HERE TO INSERT THE NEW CLASSES INTO THE DATABASE 

	$conn = mysql_connect($dbhost, $dbuser, $dbpass);
        if(! $conn ){
	  die('Could not connect: ' . mysql_error());
        }
	# the for loop iterates the array and inserts each class in DB
	# if to avoid warning on empty array 
	if(count($class)){
	  foreach($class as $data){
	    $sql = "INSERT INTO `npatel10`.`course_taken` (`student_id`, `course_id`, 'completed') VALUES ('$ID', '$data', 'R') ON DUPLICATE KEY UPDATE student_id= student_id, course_id= course_id;";
	    mysql_select_db($dbName);
	    $retval = mysql_query( $sql, $conn );
	    if(! $retval ){
	      die('Could not insert data: ' . mysql_error());
	    }
	  }
	}
	// close connection 
        mysql_close($conn);

	echo "<b>You have successfully registered above classes, and the data is stored in the database.</b><br><br>\n"; 

	?>
	<a class="return" href="index.php">Return to Homepage</a>
<?php }elseif(!empty($classErr)) {
  echo "<b>Please follow the error message to edit your input classes in order to register.</b><br><br>\n"; ?>
  <form><input Type="button" value="Back" onClick="history.go(-1);return true;"></form>
<?php }

?>

</div>



</body>
<div id="footer">
Copyright www.umbc.edu
</div>
</html>
