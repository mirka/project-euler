// Discover all the fractions with an unorthodox cancelling method.

#include <stdio.h>
#include <stdbool.h>

int main() {
  bool isCurious(const int n, const int d);
  
  for (int d = 11; d <= 99; d++) {
    for (int n = 10; n < d; n++) {
      if (n % 10 != 0 && d % 10 != 0) { // if non-trivial
        isCurious(n, d);
      }
    }
  }
  
  return 0;
}

bool isCurious(const int n, const int d) {
  double cancelDigit(char digits[], const char cancel, const int canceled_n);
  
  char digits[5];
  double canceled_value = 0;
  
  sprintf(digits, "%i%i", n, d);
  
  if (digits[0] == digits[2] || digits[0] == digits[3]) {
    canceled_value = cancelDigit(digits, digits[0], digits[1] - '0');
  } else if (digits[1] == digits[2] || digits[1] == digits[3]) {
    canceled_value = cancelDigit(digits, digits[1], digits[0] - '0');
  }
  
  if ((double)n / d == canceled_value) {
    printf("CURIOUS! %i / %i\n", n, d);
    return true;
  }
  return false;
}

// Print the result of a digit cancel and return the quotient
double cancelDigit(char digits[], const char cancel, const int canceled_n) {
  int canceled_d;
  
  for (int i = 2; i < 4; i++) {
    if (digits[i] != cancel) {
      canceled_d = digits[i] - '0';
    }
  }
  return (double)canceled_n / canceled_d; 
}