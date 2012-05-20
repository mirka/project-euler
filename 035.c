// How many circular primes are there below one million?

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int main() {
  bool isPrime(long n);
  bool rotationsArePrime(long n);
  
  int count = 0;
  
  for (long i = 2; i < 1000000; i++) {
    if (isPrime(i) && rotationsArePrime(i)) {
      count++;
    }
  }
  
  printf("%i\n", count);
  
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

bool rotationsArePrime(long n) {
  void shiftDigits(char arr[]);
  bool isPrime(long n);

  char arr[7];
  sprintf(arr, "%li", n);
  
  int digit_count = floor(log10(n) + 1);
    
  for (int i = 1; i < digit_count; i++) {
    shiftDigits(arr);
    if (!isPrime(atol(arr))) {
      return false;
    }
  }
  return true;
}

void shiftDigits(char arr[]) {
  char first_digit;
  int i = 0;
  
  first_digit = arr[0];
  
  // Shift array
  while (arr[i + 1] != '\0') {
    arr[i] = arr[i + 1];
    i++;
  }
  
  arr[i] = first_digit;
  arr[++i] = '\0';
}