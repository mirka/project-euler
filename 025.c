// What is the first term in the Fibonacci sequence to contain 1000 digits?

#include <stdio.h>

int main () {
  void addArrays(int addThis[], int toThis[]);
  
  int i = 1;
  int stop_at_digits = 1000;
  int stop_at_index = 1000 - stop_at_digits;
  
  int fib1[1000] = {0};
  int fib2[1000] = {0};
  
  fib1[999] = 1;
  fib2[999] = 1;
  
  while (i < 10000 /* arbitrary upper bound */) {
    addArrays(fib1, fib2);
    addArrays(fib2, fib1);
    i++;
    if (fib1[stop_at_index] != 0 || fib2[stop_at_index] != 0) {
      break;
    }
  }
  
  printf("Fib1 = F%i, Fib2 = F%i\n", i * 2, (i * 2) - 1);
  printf("Target digits:\n");
  printf("Fib1: %i, Fib2: %i\n", fib1[stop_at_index], fib2[stop_at_index]);
  
  
  return 0;
}

// Add two long number-like arrays
void addArrays(int addThis[], int toThis[]) {
  void incrementDigit(int *arr, const int i);
  
  for (int i = 0; i < 1000; i++) {
    toThis[i] += addThis[i];
    if (toThis[i] > 9) { // carry over
      toThis[i] -= 10;
      incrementDigit(toThis, i - 1);
    }
  }
}

// Increment digit at index i
void incrementDigit(int *arr, const int i) {
  
  if (*(arr + i) == 9) {
    incrementDigit(arr, i - 1);
    *(arr + i) = 0;
  } else {
    *(arr + i) += 1;
  }
}
