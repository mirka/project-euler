// How many letters would be needed to write all the numbers in words from 1 to 1000?

#include <stdio.h>

int main () {
  int threeDigitLetterCount(int n);
  int count = 0;
  
  for (int i = 1; i < 1000; i++) {
    count += threeDigitLetterCount(i);
  }
  
  count += 11 /* one thousand */;
  
  printf("%i\n", count);

  return 0;
}

// Returns number of letters used given a two-digit non-negative number n
int twoDigitLetterCount(int n) {
  int zero_to_nineteen[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4,
                             3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
  int twenty_to_ninety[] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };

  if (n < 20) {
    return zero_to_nineteen[n];
  } else {
    return twenty_to_ninety[(int)(n / 10)] + zero_to_nineteen[n % 10];
  }
}

// Returns number of letters used given a three-digit non-negative number n
int threeDigitLetterCount(int n) {
  int twoDigitLetterCount(int n);
  
  int lead_digit = n / 100;
  int last_two_digits = n % 100;
  int suffix = (last_two_digits == 0) ? 7 /* hundred */ : 10 /* hundred and */;
  
  if (lead_digit == 0) {
    suffix = 0;
  }
  
  return twoDigitLetterCount(lead_digit) + suffix + 
         twoDigitLetterCount(last_two_digits);
}