// Find the sum of all numbers that can be written as pandigital products.

#include <stdio.h>
#include <stdbool.h>

int main() {
  void findPandigitals(const int a_min, const int a_max,
                       const int b_min, const int b_max,
                       const int prod_min, const int prod_max);
  
  // 2-digit * 3-digit = 4-digit
  findPandigitals(12, 81, 123, 833, 1000, 9999);
  
  // 1-digit * 4-digit = 4-digit
  findPandigitals(2, 8, 1234, 4315, 1000, 9999);
  
  return 0;
}

// Find pandigital expressions a * b = c
void findPandigitals(const int a_min, const int a_max,
                     const int b_min, const int b_max,
                     const int prod_min, const int prod_max) {
  bool isPandigital(char *arr);
  char arr[10];
  int prod;
  
  for (int a = a_min; a <= a_max; a++) {
    for (int b = b_min; b <= b_max; b++) {
      prod = a * b;
      if (prod >= prod_min && prod <= prod_max) {
        sprintf(arr, "%i%i%i", a, b, prod);
        if (isPandigital(arr)) {
          printf("%i * %i = %i\n", a, b, prod);
        }
      }
    }
  }

}

// Checks whether sequence uses digits 1 thru 9 exactly once
bool isPandigital(char *arr) {
  bool used[10] = {false};
  int n;
  
  while (*arr != '\0') {
    n = *arr - '0';
    if (used[n] == true || n == 0) {
      return false;
    }
    used[n] = true;
    arr++;
  }
  return true;
}