// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main () {
  void getAbundantNums(int a, const int b, bool arr[]);
  bool isSumOfTwoAbNums(const unsigned int n, bool arr[]);
  
  unsigned int end = 28123;
  bool ab_num_arr[28123];
  
  long int sum = 0;
  int count = 0;
  
  getAbundantNums(12, end, ab_num_arr);
  
  for (int i = 0; i < end; i++) {
    if (ab_num_arr[i] == true) {
    }
  }
  
  for (unsigned int i = 1; i < end; i++) {
    if (! isSumOfTwoAbNums(i, ab_num_arr)) {
      sum += i;
      count++;
    }
  }
  
  printf("Count: %i\n", count);
  printf("Sum: %li\n", sum);
  
  return 0;
}

// Returns the sum of proper divisors of n.
unsigned int sumOfDivisors(const int n) {
  unsigned int sum = 1; // always divisible by at least 1
  int sqrt, i;
  
  if (n <= 3) {
    return 1;
  }

  sqrt = sqrtf(n);
  
  if (sqrtf(n) == sqrt /* int */) {
    sum += sqrt;
    i = sqrt - 1;
  } else {
    i = sqrt;
  }
    
  // Test all possible divisors, counting down from sqrt(n) to 2.
  // If evenly divisible, add divisor pair to sum.
  while (i > 1) {
    if (n % i == 0) {
      sum += i;
      sum += n / i;
    }
    i--;
  }
  return sum;
}


// Populates an array from index a to b whether that index is an abundant num.
void getAbundantNums(int a, const int b, bool arr[]) {
  unsigned int sumOfDivisors(const int n);
    
  while (a <= b) {
    arr[a] = (sumOfDivisors(a) > a) ? true : false;
    a++;
  }
}

// Returns whether n can be written as the sum of two abundant nums,
// given an boolean array of abundant nums
bool isSumOfTwoAbNums(const unsigned int n, bool arr[]) {
  int limit = n / 2;
  
  for (unsigned int i = 12; i <= limit; i++) {
    if (arr[i] == true && arr[n - i] == true) {
      return true;
    }
  }
  return false;
}