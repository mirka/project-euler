// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int main() {
  bool isValid(int n, int *pow5);
  void populatePowers(int exp, int arr[]);
  
  int pows[10];
  long int sum = 0;
  
  populatePowers(5, pows);
  
  for (int i = 2; i <= 999999; i++) {
    if (isValid(i, pows)) {
      printf("%i\n", i);
      sum += i;
    }
  }
  
  printf("Sum: %li\n", sum);
  
  return 0;
}

// Populate power array
void populatePowers(int exp, int arr[]) {
  for (int i = 0; i < 10; i++) {
    arr[i] = pow(i, exp);
  }
}

// Returns whether n can be written as the sum of fifth powers of their digiits
bool isValid(int n, int *pows) {
  char seq[9];
  int digit;
  long int sum = 0;
  
  sprintf(seq, "%i", n);
  
  for (int i = 0; seq[i] != '\0'; i++) {
    digit = seq[i] - '0';
    sum += pows[digit];
    
    if (sum > n) {
      return false;
    }
  }
  
  if (sum == n) {
    return true;
  } else {
    return false;
  }
}