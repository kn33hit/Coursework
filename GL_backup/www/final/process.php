<?php

$servername = "studentdb-maria.gl.umbc.edu";
$username = "npatel10";
$password = "npatel10";
$dbname = "npatel10";

$con = mysql_connect("$servername", "$username", "$password");
	if (!$con){
		echo '<script type="text/javascript">alert("CANNOT CONNECT TO DB: mysql_connect error!")</script>';
		exit;
	}

	$db = mysql_select_db("$dbname", $con);
	if(! $db){

		echo '<script type="text/javascript">alert("CANNOT SELECT DB: mysql_select_db error!")</script>';
		exit;
	}
// neds to be update query i just dont have time anymore
	$sql = 'SELECT *
			FROM `Parking_Lot`;';

	$result =mysql_query($sql);
	if(! $result){
			print("ERROR updating data");
			exit;
	}

	$num = mysql_numrows($result);
	$i=0;
	while ($i < $num) {
		$lot_name = mysql_result($result, $i, 'lot_name');
		echo $eachClass;		
		$i++;
	}


// $con->close(); this is throwing an error so i got rid of it

?>  

?>