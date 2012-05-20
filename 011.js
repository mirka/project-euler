// What is the greatest product of four adjacent numbers on the same straight line in the 20 by 20 grid?

var myString = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

function SquareMatrix(numString, gridSize) {
	var myArray = numString.split(" ");
		
	if (myArray.length / gridSize != gridSize) {
		return "Grid is not a square.";
	}
	
	for (var i = 0; i < myArray.length; i++) {
		myArray[i] = parseInt(myArray[i], 10);
	}
	
	for (var i = 0; i < gridSize; i++) {
		this[i] = myArray.splice(0, 20);
	}
		
	this.gridSize = this[0].length;
}

// Util: Find the greatest product of n adjacent numbers in an array of numbers
function maxProdOfAdjNums(n, num_arr) {
	var max_prod = 0;
	var this_prod = 0;
	var i = 0;
	
	// Calculate product of n numbers following the number with index i.
	// Return 0 if not enough numbers are left in array
	function getAdjProdFrom(n, i) {
		var prod = 1;
		var end_i = i + n;
		
		if (end_i > num_arr.length) {
			return 0;
		}
		
		while (i < end_i && i < num_arr.length) {
			prod *= num_arr[i++];
		}
		return prod;
	}
	
	// Calculate the next n-adjacent product by dividing out the first factor
	// and multiplying the next factor in the array
	while ((i + n) <= num_arr.length) {
		if (this_prod == 0) {
			this_prod = getAdjProdFrom(n, i); /* get next n-adjacent product */
		} else {
			this_prod = this_prod / num_arr[i - 1] * num_arr[i + n - 1];
		}
		i++;
		max_prod = Math.max(this_prod, max_prod);
	}
	return max_prod;
}

// Find the greatest product of n adjacent numbers
// in the rows and columns of a SquareMatrix
function maxInRowsAndColumns(n, matrix) {
	var this_row, this_column;
	var max_prod = 0;
	var length = matrix.gridSize;
	
	// Return array of numbers in the n-th column position
	function getColumn(n) {
		var column_arr = [];
		
		for (var i = 0; i < length; i++) {
			column_arr.push(matrix[i][n]);
		}
		return column_arr;
	}
	
	for (var i = 0; i < length; i++) {
		this_row = maxProdOfAdjNums(n, matrix[i]);
		this_column = maxProdOfAdjNums(n, getColumn(i));
		max_prod = Math.max(this_row, this_column, max_prod);
	}
	return max_prod;
}

// Find the greatest product of n adjacent numbers
// in the diagonals of a SquareMatrix
function maxInDiagonals(n, matrix) {
	var d = n - 1; /* n as zero-based index */
	var length = matrix.gridSize;
	
	/* Note: "forward diagonal" as in forward slash,
	   "backward diagonal" as in back slash */
	
	// Return array of numbers in the diagonal starting from
	// number coordinates {r, c}, given a string specifying the direction of
	// the diagonal, "forward" or "backward"
	function getDiagonal(r, c, direction) {
		var diag_arr = [];
		
		if (direction == "forward") {
			while (r < length && c >= 0) {
				diag_arr.push(matrix[r++][c--]);
			}
		} else {
			while (r < length && c < length) {
				diag_arr.push(matrix[r++][c++]);
			}
		}
		return diag_arr;
	}
	
	// Find greatest product in diagonals of direction "forward" or "backward"
	function maxOfDiags(direction) {
		var this_prod;
		var max_prod = 0;
		
		var c, c_len, edge;
		
		if (direction == "forward") {
			c = d;
			c_len = length;
			edge = length - 1;
		} else {
			c = 0;
			c_len = length - d;
			edge = 0;
		}
		
		while (c < c_len) { /* from topmost row */
			this_prod = maxProdOfAdjNums( n, getDiagonal(0, c, direction) );
			max_prod = Math.max(this_prod, max_prod);
			c++;
		}
		for (var r = 1; r < (length - d); r++) { /* from left/rightmost column */
			this_prod = maxProdOfAdjNums( n, getDiagonal(r, edge, direction) );
			max_prod = Math.max(this_prod, max_prod);
		}
		return max_prod;
	}
	
	return Math.max(maxOfDiags("forward"), maxOfDiags("backward"));
}

var my_matrix = new SquareMatrix(myString, 20);
Math.max( maxInRowsAndColumns(4, my_matrix),
          maxInDiagonals(4, my_matrix) );
