// Finding the nth digit of the fractional part of the irrational number.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
  int nthDigitFromEnd(long i, int n);

  int digits;
  long digit_i = 0;
  
  long targets[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
  int tar_i = 0;
  
  int this_digit;
  int prod = 1;
  
  for (long i = 1; i < 1000000; i++) {
    digits = floor(log10(i)) + 1;
    digit_i += digits;
    
    if (digit_i >= targets[tar_i]) {
      this_digit = nthDigitFromEnd(i, (int)(digit_i - targets[tar_i]));
      printf("%i\n", this_digit);
      prod *= this_digit;
      tar_i++;
      
      if (tar_i == 7) {
        break; 
      }
    }
  }
  
  printf("Product of digits: %i\n", prod);
  
  return 0;
}

// Returns the digit with index i of n, counting from the end
int nthDigitFromEnd(long n, int i) {
  char num[10];
  sprintf(num, "%li", n);
  
  long num_i = strlen(num) - i - 1;
  
  return (*(num + num_i)) - '0';
}