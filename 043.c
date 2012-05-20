// Find the sum of all pandigital numbers with an unusual sub-string divisibility property.

// THIS BRUTE FORCE TAKES TOO MUCH TIME. WAS ABLE TO SOLVE USING PEN & PAPER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define asInt(c) (c - '0')

int main() {
  bool isPandigital(char *arr);
  bool meetsSpec(char arr[], int divisor_arr[]);

  char seq[11];
  int divisor_arr[] = {2, 3, 5, 7, 11, 13, 17};
    
  for (long i = 1023456789; i <= 9876543210; i++) {
    sprintf(seq, "%li", i);
    if (meetsSpec(seq, divisor_arr) && isPandigital(seq)) {
      printf("%li\n", i);
    }
  }
  
  return 0;
}

// Checks whether sequence uses digits 0 thru 9 exactly once
bool isPandigital(char *arr) {
  bool used[10] = {false};
  int n;
  
  while (*arr != '\0') {
    n = *arr - '0';
    if (used[n] == true) {
      return false;
    }
    used[n] = true;
    arr++;
  }
  return true;
}

// Checks whether the 3-digit substrings of n have the specified property
bool meetsSpec(char arr[], int divisor_arr[]) {
  int substr;
    
  for (int i = 7; i > 0; i--) {
    substr = (asInt(arr[i]) * 100) +
             (asInt(arr[i + 1]) * 10) + asInt(arr[i + 2]);
    if (substr % divisor_arr[i - 1] != 0) {
      return false;
    }
  }
  return true;
}