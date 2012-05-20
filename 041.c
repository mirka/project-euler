// What is the largest n-digit pandigital prime that exists?

// What is the largest n-digit pandigital prime that exists?

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
  bool isPandigital(char *arr);
  bool isPrime(long n);
  
  char seq[10];
  
  for (long i = 7654321; i >= 1234567; i--) {
    sprintf(seq, "%li", i);
    if ((i % 2 != 0) &&
        isPandigital(seq) && isPrime(i)) {
      printf("FOUND! %li\n", i);
      break;
    }
  }
  
  return 0;
}

// Checks whether sequence uses digits 1 thru 7 exactly once
bool isPandigital(char *arr) {
  bool used[10] = {false};
  int n;
  
  while (*arr != '\0') {
    n = *arr - '0';
    if (used[n] == true || n == 0 || n > 7) {
      return false;
    }
    used[n] = true;
    arr++;
  }
  return true;
}

bool isPrime(long n) {
  int start;
  
  if (n <= 1) {
    return false;
  }
  
  start = sqrt(n);
  
  for (int i = 2; i <= start; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
