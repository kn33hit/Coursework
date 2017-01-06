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
  # SQL DATABASE INFO HERE!!!!!!!!!!!!!!!!!!!
  $dbhost = 'studentdb-maria.gl.umbc.edu';
  $dbuser = 'npatel10';
  $dbpass = 'npatel10';
  // usually same as the username if using gl database 
  $dbName = 'npatel10';

  // Initialize variables to null.
  $IDErr = $nameErr = $emailErr = $phoneErr ="";
  $ID = $name = $email = $phone ="";
  $classTaken = array();
  $suggestClass = array();

  //collect user input and validate the data
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["ID"])) {
      $IDErr = "Student ID is required";
    } else {
      $ID = test_input($_POST["ID"]);
      if (!preg_match("/^[a-zA-Z]{2}\d{5}$$/",$ID)) {
        $IDErr = "Invalid ID format, correct format example: ab12345";
      }
    }

    if (empty($_POST["name"])) {
      $nameErr = "Name is required";
    } else {
      $name = test_input($_POST["name"]);
      // check name only contains letters and whitespace
      if (!preg_match("/^[a-zA-Z ]*$/",$name)) {
        $nameErr = "Only letters and white space allowed";
      }
    }

    if (empty($_POST["email"])) {
      $emailErr = "Email is required";
    } else {
      $email = test_input($_POST["email"]);
      // check if e-mail address syntax is valid or not
      if (!preg_match("/([\w\-]+\@[\w\-]+\.[\w\-]+)/",$email)) {
        $emailErr = "Invalid email format";
      }
    }

    if (empty($_POST["phone"])) {
      $phoneErr = "Phone number is required";
    } else {
      $phone = test_input($_POST["phone"]);
      if (!preg_match("/^(\+\d{1,2}\s)?\(?\d{3}\)?[\s.-]?\d{3}[\s.-]?\d{4}$/",$phone)) {
        $phoneErr = "Invalid phone number format";
      }
    }

    $classTaken = $_POST['classTaken'];
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
  <li><a class="active">Validation</a></li>
  <li><a href="contact.html">Contact</a></li>
</ul>

<!-- MAIN DIV -->
<!--The main div to put the form in, which will take in all the information--> 
<div class = "mainDiv">

<?php
  //output the input info, show error if it is invalid
  $Color = "red";
  echo "<h2>Your Information:</h2>";
  echo "Student ID: ". $ID;
  echo '<p style="Color:'.$Color.'">'.$IDErr.'</p>';
  echo "Name: ". $name;
  echo '<p style="Color:'.$Color.'">'.$nameErr.'</p>';
  echo "Email: ". $email;
  echo '<p style="Color:'.$Color.'">'.$emailErr.'</p>';
  echo "Phone Number: ". $phone;
  echo '<p style="Color:'.$Color.'">'.$phoneErr.'</p>';

  //generate a suggested class list based on the classes taken
  if($IDErr == "" and $nameErr == "" and $emailErr == "" and $phoneErr == "") {
    echo "<h3>Classes Taken:</h3>";
    $num = count($classTaken);
    if($num > 0) {
      sort($classTaken);
      for($i=0; $i < count($classTaken); $i++){
        echo($classTaken[$i] . " ");
      }

      //math courses
      if(!in_array("MATH151", $classTaken)){
        array_push($suggestClass, "MATH151");
      }else{
        if(!in_array("MATH152", $classTaken)){
	  array_push($suggestClass, "MATH152");
        }else{
	  if(!in_array("MATH221", $classTaken)){
	    array_push($suggestClass, "MATH221");
          }
          if(!in_array("STAT355", $classTaken)){
	    array_push($suggestClass, "STAT355");
          }
        }
      }
		
      //science courses
      if(!in_array("BIOL100", $classTaken) and !in_array("BIOL141", $classTaken) and !in_array("CHEM101", $classTaken) and !in_array("PHYS121", $classTaken)){
        array_push($suggestClass, "BIOL100");
       array_push($suggestClass, "BIOL141");
       array_push($suggestClass, "CHEM101");
        array_push($suggestClass, "PHYS121");
      }else{
        if(in_array("BIOL100", $classTaken) and !in_array("BIOL301", $classTaken)){
	  if(!in_array("BIOL142", $classTaken))
					if(!in_array("CHEM102", $classTaken))
						if(!in_array("PHYS122", $classTaken))
							array_push($suggestClass, "BIOL301");
			}
			if(in_array("BIOL141", $classTaken) and !in_array("BIOL142", $classTaken)){
				if(!in_array("BIOL301", $classTaken))
					if(!in_array("CHEM102", $classTaken))
						if(!in_array("PHYS122", $classTaken))
							array_push($suggestClass, "BIOL142");
			}
			if(in_array("CHEM101", $classTaken) and !in_array("CHEM102", $classTaken)){
				if(!in_array("BIOL301", $classTaken))
					if(!in_array("BIOL142", $classTaken))
						if(!in_array("PHYS122", $classTaken))
							array_push($suggestClass, "CHEM102");
			}
			if(in_array("PHYS121", $classTaken) and !in_array("PHYS122", $classTaken)){
				if(!in_array("BIOL301", $classTaken))
					if(!in_array("BIOL142", $classTaken))
						if(!in_array("CHEM101", $classTaken))
							array_push($suggestClass, "PHYS122");
			}
      }

		//computer science courses
		if(!in_array("CMSC201", $classTaken)){
			array_push($suggestClass, "CMSC201");
		}else {
			if(!in_array("CMSC202", $classTaken)){
				array_push($suggestClass, "CMSC202");
			}else{
				if(!in_array("CMSC304", $classTaken)){
					array_push($suggestClass, "CMSC304");
				}
				if(!in_array("CMSC486", $classTaken)){
					array_push($suggestClass, "CMSC486");
				}
				if(!in_array("CMSC484", $classTaken)){
					array_push($suggestClass, "CMSC484");
				}
				if(!in_array("CMSC203", $classTaken)){
					array_push($suggestClass, "CMSC203");
				}else{
					
					if(!in_array("CMSC451", $classTaken)){
						array_push($suggestClass, "CMSC451");
					}
					if(!in_array("CMSC452", $classTaken)){
						array_push($suggestClass, "CMSC452");
					}
					if(!in_array("CMSC457", $classTaken)){
						array_push($suggestClass, "CMSC457");
					}
					if(!in_array("CMSC232", $classTaken)){
						array_push($suggestClass, "CMSC232");
					}
					if(!in_array("CMSC291", $classTaken)){
						array_push($suggestClass, "CMSC291");
					}
					if(!in_array("CMSC299", $classTaken)){
						array_push($suggestClass, "CMSC299");
					}
					if(!in_array("CMSC313", $classTaken)){
						array_push($suggestClass, "CMSC313");
					}else{
						array_push($suggestClass, "CMSC411");
					}
					if(!in_array("CMSC331", $classTaken)){
						array_push($suggestClass, "CMSC331");
					}else{
						if(!in_array("CMSC432", $classTaken)){
							array_push($suggestClass, "CMSC432");
						}
						if(!in_array("CMSC433", $classTaken)){
							array_push($suggestClass, "CMSC433");
						}
						if(!in_array("CMSC473", $classTaken)){
							array_push($suggestClass, "CMSC473");
						}
					}

					if(!in_array("CMSC341", $classTaken)){
						array_push($suggestClass, "CMSC341");
					}else{
						if(!in_array("CMSC427", $classTaken)){
							array_push($suggestClass, "CMSC427");
						}
						if(!in_array("CMSC436", $classTaken)){
							array_push($suggestClass, "CMSC436");
						}
						if(!in_array("CMSC437", $classTaken)){
							array_push($suggestClass, "CMSC437");
						}
						if(!in_array("CMSC443", $classTaken)){
							array_push($suggestClass, "CMSC443");
						}
						if(!in_array("CMSC453", $classTaken)){
							array_push($suggestClass, "CMSC453");
						}
						if(!in_array("CMSC455", $classTaken)){
							array_push($suggestClass, "CMSC455");
						}
						if(!in_array("CMSC456", $classTaken)){
							array_push($suggestClass, "CMSC456");
						}
						if(!in_array("CMSC461", $classTaken)){
							array_push($suggestClass, "CMSC461");
						}
						if(!in_array("CMSC352", $classTaken)){
							array_push($suggestClass, "CMSC352");
						}
						if(!in_array("CMSC391", $classTaken)){
							array_push($suggestClass, "CMSC391");
						}
						if(!in_array("CMSC404", $classTaken)){
							array_push($suggestClass, "CMSC404");
						}
						if(!in_array("CMSC444", $classTaken)){
							array_push($suggestClass, "CMSC444");
						}
						if(!in_array("CMSC446", $classTaken)){
							array_push($suggestClass, "CMSC446");
						}
						if(!in_array("CMSC495", $classTaken)){
							array_push($suggestClass, "CMSC495");
						}
						if(!in_array("CMSC498", $classTaken)){
							array_push($suggestClass, "CMSC498");
						}
						if(!in_array("CMSC499", $classTaken)){
							array_push($suggestClass, "CMSC499");
						}
						if(in_array("CMSC341", $classTaken) and in_array("STAT355", $classTaken)){
							array_push($suggestClass, "CMSC441");
						}
						if(!in_array("CMSC471", $classTaken)){
							array_push($suggestClass, "CMSC471");
						}else{
							if(!in_array("CMSC477", $classTaken)){
								array_push($suggestClass, "CMSC477");
							}
							if(!in_array("CMSC478", $classTaken)){
								array_push($suggestClass, "CMSC478");
							}
							if(!in_array("CMSC479", $classTaken)){
								array_push($suggestClass, "CMSC479");
							}
						}
						if(!in_array("CMSC475", $classTaken)){
							array_push($suggestClass, "CMSC475");
						}
						if(!in_array("CMSC476", $classTaken)){
							array_push($suggestClass, "CMSC476");
						}
						if(!in_array("CMSC481", $classTaken)){
							array_push($suggestClass, "CMSC481");
						}
						if(in_array("CMSC461", $classTaken) and in_array("CMSC481", $classTaken)){
							if(!in_array("CMSC465", $classTaken) or !in_array("CMSC466", $classTaken)){
								if(!in_array("CMSC465", $classTaken) and !in_array("CMSC466", $classTaken)){
									array_push($suggestClass, "CMSC465");
									array_push($suggestClass, "CMSC466");
								}
								
							}
						}
						$filtered = 0;
						foreach ($classTaken as $element) {
   							if (preg_match("@^CMSC4@",$element)){ 
        								$filtered = 1;
  							}
						}
						if($filtered == 1){
							if(!in_array("CMSC447", $classTaken)){
								array_push($suggestClass, "CMSC447");
							}else{
								if(!in_array("CMSC448", $classTaken)){
									array_push($suggestClass, "CMSC448");
								}
							}
						}
			
					}
					if(in_array("CMSC313", $classTaken) and in_array("CMSC341", $classTaken)){
						if(!in_array("CMSC421", $classTaken)){
							array_push($suggestClass, "CMSC421");
						}else{
							if(!in_array("CMSC426", $classTaken)){
								array_push($suggestClass, "CMSC426");
							}
							if(!in_array("CMSC483", $classTaken)){
								array_push($suggestClass, "CMSC483");
							}
						}
						if(in_array("CMSC421", $classTaken) and in_array("CMSC481", $classTaken)){
							if(!in_array("CMSC487", $classTaken)){
								array_push($suggestClass, "CMSC487");
							}
						}
						if(!in_array("CMSC435", $classTaken)){
							array_push($suggestClass, "CMSC435");
						}else{
							if(in_array("CMSC435", $classTaken) and in_array("CMSC471", $classTaken)){
								if(!in_array("CMSC493", $classTaken)){
									array_push($suggestClass, "CMSC493");
								}
							}
						}
						
					}
					if(in_array("CMSC331", $classTaken) and in_array("CMSC341", $classTaken)){
						if(!in_array("CMSC431", $classTaken)){
							array_push($suggestClass, "CMSC431");
						}
					}


				}

			
			}
		}
	} else {
		array_push($suggestClass, "CMSC201");
		array_push($suggestClass, "MATH151");
		array_push($suggestClass, "BIOL100");
		array_push($suggestClass, "BIOL141");
		array_push($suggestClass, "CHEM101");
		array_push($suggestClass, "PHYS121");
		echo "You haven't taken any class<br>\n";
	}


	echo "<h3>Suggested Classes:</h3>";
	sort($suggestClass);
	for($i=0; $i < count($suggestClass); $i++){
   		echo($suggestClass[$i] . " ");
	}
	echo "<br><br>";
	
}
	

?>

<?php if($IDErr == "" and $nameErr == "" and $emailErr == "" and $phoneErr == "") {

	# SQL CODE HERE TO INSERT STUDENT INFORMATION IN THE TABLES
	# THE TABLE NAME IS STUDENTS 
	$conn = mysql_connect($dbhost, $dbuser, $dbpass);
	if(! $conn ){
	    die('Could not connect: ' . mysql_error());
	}
	// on duplicate to make sure no warnings or errprs are generated for 
	// duplicated key 
	$sql = "INSERT INTO `npatel10`.`Students` (`student_id`, `name`, `email`, `phone`) VALUES ('$ID', '$name', '$email', '$phone') ON DUPLICATE KEY UPDATE name=name, email=email, phone = phone;";
	mysql_select_db($dbName);
	$retval = mysql_query( $sql, $conn );
	if(! $retval){
	  die('Could not insert data: ' . mysql_error());
	}

	# SQL code to insert the classes previously selected
	// if statement to avoid warning if its empty 
	if(count($classTaken)){
	  // insert each class
	    foreach($classTaken as $data){
	      $sql = "INSERT INTO `course_taken`(`student_id`, `course_id`, 'completed') VALUES ('$ID','$data', 'P') ON DUPLICATE KEY UPDATE student_id= student_id, course_id= course_id;";
	      mysql_select_db($dbName);
	      $retval = mysql_query( $sql, $conn );
	      if(! $retval ){
		die('Could not insert data: ' . mysql_error());
	      }
	    }
	  }
	// close connection
	mysql_close($conn);


	?>
         
	<form method="post" action="register.php">
 	  <h2>Please enter the classes you want to register:</h2>
	 <input type='hidden' name="suggestClass" value="<?php echo htmlentities(serialize($suggestClass)); ?>" >
	  Student ID:<br> 
   	  <input type="text" name="ID" value="<?php echo htmlspecialchars($ID); ?>" readonly>
   	  <br>
   	  Name:<br> 
   	  <input type="text" name="name" value="<?php echo htmlspecialchars($name); ?>" readonly>
   	  <br>
   	  E-mail:<br> 
  	  <input type="text" name="email" value="<?php echo htmlspecialchars($email); ?>" readonly>
  	  <br>
  	  Phone:<br>
  	  <input type="text" name="phone" value="<?php echo htmlspecialchars($phone); ?>" readonly>
   	  <br><br>
	  <p>Enter the class ID only, example: CMSC201<p>
 	  Class one:<br> 
  	  <input type="text" name="class1">
  	  <br>
          Class two:<br> 
  	  <input type="text" name="class2">
  	  <br>
	  Class three:<br> 
  	  <input type="text" name="class3">
  	  <br>
          Class four:<br> 
  	  <input type="text" name="class4">
 	  <br>
           Class five:<br> 
  	  <input type="text" name="class5">
  	  <br>
  	  <input class="submit" type="submit" name="submit" value="Submit"> 
	 
	</form>

<?php  } 	

else {
	echo "<br>\n<b>Please fill out the required information in order to register.</b><br><br>\n";
?>
	<form><input Type="button" value="Back" onClick="history.go(-1);return true;"></form>
<?php }
?>

</div>

  <div id="footer">
    Copyright www.umbc.edu
  </div>
</body>
</html>
