<?php 
class Common
{
  var $conn;
  var $debug;
  
  function Common($debug)
  {
    $this->debug = $debug; 
    $rs = $this->connect("npatel10"); // db name really here
    return $rs;
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  
  function connect($db)// connect to MySQL
  {
    $conn = @mysql_connect("studentdb-maria.gl.umbc.edu", "npatel10", "npatel10") or die("Could not connect to MySQL");
    $rs = @mysql_select_db($db, $conn) or die("Could not connect select $db database");
    $this->conn = $conn; 
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  
  function executeQuery($sql, $filename) // execute query
  {
    if($this->debug == true) { echo("$sql <br>\n"); }
    $rs = mysql_query($sql, $this->conn) or die("Could not execute query '$sql' in $filename"); 
    return $rs;
  }
} // ends class, NEEDED!!
$dbname = "npatel10";
$debug =  false;
$db = new Common($debug);
$db->connect($dbname);
$num = "2";
$sql = "SELECT CustomerName FROM Customers WHERE CustomerNum = $num";
$rs = $db->executeQuery($sql, "file");
while($row = mysql_fetch_array($rs)) {
  echo $row["question"];
}
?>
