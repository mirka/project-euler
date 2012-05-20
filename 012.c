// What is the value of the first triangle number to have over five hundred divisors?

// Answer ran in 0.534 secs

#include <stdio.h>
#include <math.h>

int main () {
  long int answer(long int i);
  
  printf("%li\n", answer(7));
}

// Return n-th triangular number
long int triangular(long int n) {
  return (n * (n + 1)) / 2;
}

// Return the number of divisors of non-negative int n
int divisorCount(long int n) {
  int div_count = 2; /* every number > 1 is divisible by 1 and itself */
  double sqrt_n = sqrt(n);
  int div_candidate = (int)sqrt_n;
  
  if (n == 0 || n == 1) {
    return (int)n;
  }
  
  if (sqrt_n == div_candidate) { /* if sqrt of n is an integer */
    div_count++;
    div_candidate--;
  }
  
  while (div_candidate > 1) {
    if (n % div_candidate == 0) {
      div_count += 2;
    }
    div_candidate--;
  }
  return div_count;
}

// Find the value of the first triangular number to have more than 500 divisors,
// given the starting triangle number index to test
long int answer(long int i) {
  long int triangular(long int n);
  int divisorCount(long int n);
  
  long int tri;
  
  while (i) {
    tri = triangular(i++);
    if (divisorCount(tri) > 500) {
      return tri;
    }
  }
}