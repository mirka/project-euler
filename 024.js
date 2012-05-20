// DOES NOT SCALE :(

var arr = [0,1,2,3,4,5,6,7,8,9];
var end_perm_i = 1000000;
var perm = [];
var perm_i = 0;

// Prints current permutation to console
function printPerm(subarr1, subarr2) {
	perm_i++;
	perm = subarr1.concat(subarr2);
	
	if (perm_i == end_perm_i) {
		console.log(perm_i + ": " + perm.join(""));
	}
}

// Swap the last digit of subarr1 with next biggest digit in subarr2.
// Returns array [subarr1, subarr2]
function carryOver(subarr1, subarr2) {
	var sa1_last_i = subarr1.length - 1;
	var sa1_last = subarr1[sa1_last_i];
	
	subarr2.sort();
	
	for (var i = 0; i < subarr2.length; i++) {
		if (subarr2[i] > sa1_last) { // swap values
			subarr1[sa1_last_i] = subarr2[i];
			subarr2[i] = sa1_last;
			return [subarr1, subarr2];
		}
	}
	return [subarr1, subarr2]; // if no match, return unchanged
}


function foo(subarr1, subarr2, sa2_count) {
	var subarrs = [];
		
	if (sa2_count == 2) {
		printPerm(subarr1, subarr2.sort());
		printPerm(subarr1, subarr2.reverse());
		
		// If last digit of subarr1 is maxed out, move it to subarr2
		while (subarr1[subarr1.length - 1] > Math.max.apply(null, subarr2)) {
			subarr2.push(subarr1.pop());
		}
		
		if (subarr1.length == 0 || perm_i == end_perm_i) {
			console.log("DONE! perm_i = " + perm_i);
			return;
		}
		
		subarrs = carryOver(subarr1, subarr2);
		foo(subarrs[0], subarrs[1], subarrs[1].length);
		
		
	} else {
		subarr1.push(subarr2.shift()); // move first digit of subarr2 to subarr1
		foo(subarr1, subarr2, --sa2_count);
	} 
}

foo([], arr, arr.length);