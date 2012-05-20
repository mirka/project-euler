// Find the sum of all numbers which are equal to the sum of the factorial of their digits.

#include <stdio.h>

int main() {
  void populateFactorialArr(long int arr[]);
  long int sumOfFacs(long int n, long int fact_arr[]);
  
  long int factorial[10] = {0};
  populateFactorialArr(factorial);

  for (long int i = 10; i < 2999999; i++) {
    if (sumOfFacs(i, factorial) == i) {
      printf("CURIOUS! %li\n", i);
    }
  }
  
  
  return 0;
}

void populateFactorialArr(long int arr[]) {
  long int factorial(const int n);
  
  for (int i = 0; i < 10; i++) {
    arr[i] = factorial(i);
  }
}

long int factorial(const int n) {
  long int prod = 1;
  
  for (int i = n; i > 0; i--) {
    prod *= i;
  }
  return prod;
}

long int sumOfFacs(long int n, long int fact_arr[]) {
  char arr[10];
  sprintf(arr, "%li", n);
  
  long int sum = 0;
  
  for (int i = 0; arr[i] != '\0'; i++) {
    sum += fact_arr[arr[i] - '0'];
    if (sum > n) {
      return 0;
    }
  }
  return sum;
}