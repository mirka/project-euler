// Evaluate the sum of all amicable pairs under 10000.

#include <stdio.h>
#include <math.h>

int main () {
  int sumOfDivisors(int n, int sum_table[]);
  
  int sum_table[10001] = {0};
  int amicable1, amicable2;
  int sum_of_amicables = 0;
  
  for (int i = 3; i <= 10000; i++) {
    amicable1 = sumOfDivisors(i, sum_table);
    amicable2 = (amicable1 <= 10000) ? sumOfDivisors(amicable1, sum_table) : 0;
    
    if (i == amicable2 && amicable1 != amicable2) {
      sum_of_amicables += amicable1;
      printf("Pair: %i, %i\n", amicable1, amicable2);
    }
  }
  
  printf("Sum of amicable numbers: %i\n", sum_of_amicables);
  
  return 0;
}

// Returns the sum of proper divisors of n.
// Saves and reads already-calculated values from sum_table
int sumOfDivisors(int n, int sum_table[]) {
  int sum = 1; // always divisible by at least 1
  int sqrt;
  
  if (n <= 3) {
    return 1;
  }
  
  if (sum_table[n]) {
    return sum_table[n];
  }
  
  sqrt = sqrtf(n);
  
  if (n % sqrt == 0) {
    sum += sqrt;
  }
  
  // Test all possible divisors, counting down from sqrt(n) to 2.
  // If evenly divisible, add divisor pair to sum.
  for (int i = sqrt; i > 1; i--) {
    if (n % i == 0) {
      sum += i;
      sum += n / i;
    }
  }
  sum_table[n] = sum;
  return sum;
}