// What is the sum of the digits of the number 2^1000?

#include <stdio.h>
#include <math.h>

int main () {
  double answer = pow(2, 1000);
  char arr[400];
  double count = 0;
  
  sprintf(arr, "%f", answer);
  
  for (int i = 0; arr[i] != '.'; i++) {
    count += arr[i] - '0';
  }
  
  printf("%g\n", count);
}