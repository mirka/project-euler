<html>
<head>
<title>JavaScript</title>
</head>
<body>


<script language="JavaScript" type="text/javascript">

function addEvenFib(maxFib) {
	var prev1Fib = 2, prev2Fib = 1;
	var fib = 0, evenFibSum = 2;

	while (0 == 0) {
		fib = prev1Fib + prev2Fib;
		if (fib > maxFib) break;
		
		prev2Fib = prev1Fib;
		prev1Fib = fib;
		
		if (fib % 2 == 0) {
			evenFibSum += fib;
		}
	}
	return evenFibSum;
}

addEvenFib(100);


</script>
</body>
</html>