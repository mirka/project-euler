// Find the longest sequence using a starting number under one million.

#include <stdio.h>

int main () {
  int collatzCount(long int n);

  int max_count;
  int max_start;
  
  int this_count;
  
  
  for (int i = 0; i <= 1000000; i++) {
    this_count = collatzCount(i);
    
    if (this_count > max_count) {
      max_count = this_count;
      max_start = i;
    }
  }
  
  printf("Start: %i, Count: %i\n", max_start, max_count);
  
  return 0;
}

// Returns count of numbers in Collatz sequence starting with n
int collatzCount(long int n) {
  int count = 1;
  
  while (n > 1) {
    count++;
    
    if (n % 2 == 0) /* even */ {
      n /= 2;
    } else /* odd */ {
      n = (3 * n) + 1;
    }
  }
  return count;
}