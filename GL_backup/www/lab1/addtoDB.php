<?php


    $dbhost = 'studentdb-maria.gl.umbc.edu';
    $dbuser = 'npatel10';
    $dbpass = 'npatel10';
    $conn = mysql_connect($dbhost, $dbuser, $dbpass);
    if(! $conn )
      {
	die('Could not connect: ' . mysql_error());
      }
$sql = 'SELECT Name FROM RecommendOs';

mysql_select_db('npatel10');
$retval = mysql_query( $sql, $conn );
if(! $retval )
  {
    die('Could not get data: ' . mysql_error());
  }
$count = 0;
$names = array();
while($row = mysql_fetch_array($retval, MYSQL_ASSOC)){
  $names[$count] = $row['Name'];
  $count++;
}
echo $count;
$name = "whasdfstever";
mysql_select_db('npatel10');                                     
$sql = "INSERT INTO `npatel10`.`RecommendOs` (`Name`) VALUES ('$name');";  
mysql_select_db('npatel10');                                             
$retval = mysql_query( $sql, $conn );                                  
if(! $retval )                                                            
  {                                                                      
    die('Could not enter data: ' . mysql_error());                       
  }                                                                      

    mysql_close($conn);
  

?>