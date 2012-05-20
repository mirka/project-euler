// Find the value of d < 1000 for which 1/d contains the longest recurring cycle.

var max_cycle = 1;
var rem_arr = [];
var this_cycle = 0; 

// Add indexOf method to Array.prototype (ECMA-262 specified algorithm)
(function addIndexOfMethod() {
	if (!Array.prototype.indexOf) {
		Array.prototype.indexOf = function (searchElement /*, fromIndex */ ) {
			"use strict";
			if (this === void 0 || this === null) {
				throw new TypeError();
			}
			var t = Object(this);
			var len = t.length >>> 0;
			if (len === 0) {
				return -1;
			}
			var n = 0;
			if (arguments.length > 0) {
				n = Number(arguments[1]);
				if (n !== n) { // shortcut for verifying if it's NaN
					n = 0;
				} else if (n !== 0 && n !== Infinity && n !== -Infinity) {
					n = (n > 0 || -1) * Math.floor(Math.abs(n));
				}
			}
			if (n >= len) {
				return -1;
			}
			var k = n >= 0 ? n : Math.max(len - Math.abs(n), 0);
			for (; k < len; k++) {
				if (k in t && t[k] === searchElement) {
					return k;
				}
			}
			return -1;
		}
	}
})();

function isPrime(n) {
	var start = Math.floor(Math.sqrt(n));
	
	for (var i = start; i > 1; i--) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// Push the (n % divisor) to rem_arr
function pushRemToArr(n, divisor) {
	var rem;
	var cycle_len;
		
	rem = n % divisor;
	
	if (this_cycle == divisor || rem == 0) { // cycle not found
		return;
	}
	
	if (rem_arr.indexOf(rem) > -1) { // cycle found
		cycle_len = rem_arr.length;
		max_cycle = cycle_len > max_cycle ? cycle_len : max_cycle;
		$.writeln(i + ": " + cycle_len);
		rem_arr = [];
	} else {
		rem_arr.push(rem);
		pushRemToArr(rem * 10, divisor);
	}
}

for (var i = 999; i > 1; i--) {
	if (isPrime(i)) {
		pushRemToArr(10, i);
	}
}