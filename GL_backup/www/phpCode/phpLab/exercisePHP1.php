<?php
$var1 $_GET ["first"];
$wage = array();
$wage[0] = $_GET ["first"];
$wage[1] = $_GET ["second"];
$wage[2] = $_GET ["third"];
$wage[3] = $_GET ["fourth"];
$wage[4] = $_GET ["fifth"];

echo("The wage amount of each bargaining employee:" );
foreach($wage as $output){
  echo("$" );
  echo("{$output}");
  echo(",");
}
?>