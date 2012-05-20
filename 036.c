// Find the sum of all numbers less than one million, which are palindromic in base 10 and base 2.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
  bool isPalin(char *str);
  void toBinary(long n, char *to_str);
  
  char dec[7];
  char bin[25];
  long sum = 0;
  
  for (long i = 0; i < 1000000; i++) {
    sprintf(dec, "%li", i);

    if (isPalin(dec)) {
      toBinary(i, bin);
      
      if (isPalin(bin)) {
        sum += i;
        printf("%li, %s\n", i, bin);
      }
    }
  }
  
  printf("Sum: %li\n", sum);

  return 0;
}

// Returns whether a string is palindromic
bool isPalin(char *str) {
  char *front = str;
  char *back = str;
  
  while (*(back + 1) != '\0') {
    back++; // point back to last non-null char in string
  }
  
  while (*front == *back) {
    front++;
    back--;
  }
  return (front > back) ? true : false;
}

// Convert a number n (0-1,000,000) to binary string
void toBinary(long n, char *to_str) {
  long this_pow;
  bool str_started = false; // flag to exclude leading zeros
  
  for (int exp = 19; exp >= 0; exp--) {
    if ((this_pow = pow(2, exp)) <= n) {
      str_started = true;
      *(to_str++) = '1';
      n -= this_pow;
    } else if (str_started) {
      *(to_str++) = '0';
    }
  }
  *to_str = '\0';
}