// Find a quadratic formula that produces the maximum number of primes for consecutive values of n.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main () {
  bool isPrime(int n);
  int primeCount(int a, int b);
  
  int max_prime = 0;
  int this_prime;
  
  for (int a = -1000; a < 1000; a++) {
    for (int b = 1; b < 1000; b++) {
      if (isPrime(b)) {
        this_prime = primeCount(a, b);
        if (this_prime > max_prime) {
          max_prime = this_prime;
          printf("a = %i, b = %i, prime count = %i\n", a, b, this_prime);
        }
      }
    }
  }
  
  printf("Max prime count: %i\n", max_prime);
  
  return 0;
}


bool isPrime(int n) {
  int start;
  
  if (n <= 1) {
    return false;
  }
  
  start = sqrt(n);
  
  for (int i = start; i > 1; i--) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// Given quadratic coefficients a and b, returns how many primes they can make
// Formula: n^2 + an + b
int primeCount(int a, int b) {
  int count = 0;
  
  for (int i = 0; i < 100; i++) {
    if (isPrime(pow(i, 2) + (a * i) + b)) {
      count++;
    } else {
      return count;
    }
  }
  return 0;
}