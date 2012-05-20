<html>
<head>
<title>JavaScript</title>
</head>
<body>


<script language="JavaScript" type="text/javascript">

var answer = function(stopNum) {
	var sum = 0;
	
	for (var i = 0; i < stopNum; i += 3) {
		sum += i;
	}
	
	for (var j = 0; j < stopNum; j += 5) {
		if (j % 3 == 0) continue;
		sum += j;
	}
	return sum;
} (1000);



</script>
</body>
</html>