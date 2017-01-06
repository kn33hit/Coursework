<?php
$dbhost = 'studentdb-maria.gl.umbc.edu';
$dbuser = 'npatel10';
$dbpass = 'npatel10';
$conn = mysql_connect($dbhost, $dbuser, $dbpass);
if(! $conn )
  {
    die('Could not connect: ' . mysql_error());
  }

$applicant_ID = "MH52312";
$Name = "Neh";
$Title = "TA";
$Dept = "CMSC";
$College = "UMBC";
$Phone = "4432139092";
$email = "npatel10@umbc.edu";
$Dept_head_name = "Lupoli";
$Dept_head_email = "something@whatever.edu";
$Company = "Dell";
$Model = "1900";
$Year_old = "4";
$Basic_specs = "sdgdfgdfg";
//$laptopOrDesktop = "laptop";
$reason = "hate it";
$replacement_to = "applle product";
$Contact_name = "Neh";
$Contact_Title = "TA";
$Contact_Dept = "CMSC";
$Contact_College = "UMBC";
$Contact_Phone = "34789923843";
$Contact_email = "jsdbsbd@jnddf.gov";

$sql = "INSERT INTO CRI" . 
"(`Applicant_ID`, `Name`, `Title`, `Dept`, `College/Division`, `Phone`, `email`, `Dept_head_name`, `Dept_head_email`, `Company`, `Model`, `Year_old`, `Basic_specs`, `reason`, `replacement_to`, `Contact_Name`, `Contact_Title`, `Contact_Dept`, `Contact_College`, `Contact_Phone`, `Contact _email`) " .
" VALUES ".
"('$applicant_ID','$Name','$Title','$Dept','$College','$Phone','$email','$Dept_head_name','$Dept_head_email','$Company','$Model','$Year_old','$Basic_specs','$reason','$replacement_to','$Contact_name','$Contact_Title','$Contact_Dept','$Contact_College','$Contact_Phone','$Contact_email')";

mysql_select_db('npatel10');
$retval = mysql_query( $sql, $conn );
if(! $retval )
  {
    die('Could not insert data: ' . mysql_error());
  }
/*
while($row = mysql_fetch_array($retval, MYSQL_ASSOC))
  {
    echo "Name is :{$row['CustomerName']} <br>";
    
    }*/
mysql_close($conn);

?>