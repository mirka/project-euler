// Find the sum of all eleven primes that are both truncatable from left to right and right to left.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int main() {
  bool isPrime(long n);
  bool isTruncPrime(long n, long *primes, int direction);
    
  long primes[80000] = {0};
  long *primes_ptr = primes;
  
  long sum = 0;
  
  for (long i = 0; i < 1000000; i++) {
    if (isPrime(i)) {
      *(primes_ptr++) = i;
      if (isTruncPrime(i, primes, 1) && 
          isTruncPrime(i, primes, -1)) {
        sum += i;
        printf("SUCCESS! %li\n", i);
      }
    }
  }
  
  printf("Sum: %li\n", sum);

  return 0;
}

bool isPrime(long n) {
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

bool isInPrimes(long n, long *primes) {
  while (*primes != 0) {
    if (*(primes++) == n) {
      return true;
    }
  }
  return false;
}

// Returns whether n is a left/right truncatable prime.
// Give direction 1 for left, -1 for right.
bool isTruncPrime(long n, long *primes, int direction) {
  void shiftDigit(char arr[]);
  void popDigit(char *arr);
  bool isInPrimes(long n, long *primes);
  
  char trunced[8];
  long trunced_n;
  void (*truncate)(char *arr) = direction > 0 ? &shiftDigit : &popDigit;
    
  sprintf(trunced, "%li", n);
  
  do {
    (*truncate)(trunced);
    trunced_n = atol(trunced);
    if (!isInPrimes(trunced_n, primes)) {
      return false;
    }
  } while (trunced_n > 9);
  return true;
}

void shiftDigit(char arr[]) {
  int i = 0;
  
  // Shift array
  while (arr[i + 1] != '\0') {
    arr[i] = arr[i + 1];
    i++;
  }
  arr[i] = '\0';
}

void popDigit(char *arr) {
  
  while (*(arr + 1) != '\0') {
    arr++;
  }
  *arr = '\0';
}