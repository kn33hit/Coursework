<!DOCTYPE html>
<html>
<head>
	<title>Car parking </title>
</head>
<script type="text/javascript">
function validateNumbers(){
	var txt = "";
    if (document.getElementById("id1").validity.rangeOverflow) {
       txt = "Value too large";
    }
    document.getElementById("demo").innerHTML = txt;

}


</script>
<body>

<h1> Update lot capacity </h1>
	<form name="my_form" action="process.php"
onsubmit="return validateNumbers()" method="post">
Lot 1-D:<input type="number" id = "lot"  min="0" max="300" name="lot1D"><br><br>
Lot 20-B:<input type="number" id = "lot"  min="0" max="300" name="lodt20B"><br><br>
Lot 29-A:<input type="number" id = "lot"  min="0" max="300" name="29A"><br><br>
Lot Stadium-A:<input type="number" id = "lot"  min="0" max="300" name="lot_sA"><br><br>
Lot 6-C:<input type="number" id = "lot"  min="0" max="300" name="lot6C"><br><br>
Lot 9-P:<input type="number" id = "lot"  min="0" max="300" name="lot9P"><br><br>
Lot 8-D:<input type="number" id = "lot"  min="0" max="300" name="lot8D"><br><br>
Lot 8-E:<input type="number" id = "lot"  min="0" max="300" name="lot8E"><br><br>
<button type="submit" value="Submit">

</form>

<p id="demo"></p>

</body>
</html>
