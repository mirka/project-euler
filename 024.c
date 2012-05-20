// What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

// TIME-CONSUMING BRUTE FORCE PROGRAM (at least it's linear…)

#include <stdio.h>
#include <stdbool.h>

int main () {
  void incrementDigit(int *arr, const int i);
  bool isPermutation(int *arr, long int * const perm_i);
  void printPerm(int *arr);
  
  int perm_candidate[] = {0,1,2,3,4,5,6,7,8,9};
  long int perm_i = 1;
  
  while (perm_i < 1000000) {
    incrementDigit(perm_candidate, 9);
    isPermutation(perm_candidate, &perm_i);
  }
  printf("Perm #%li:\n", perm_i);
  printPerm(perm_candidate);
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

// Check if array is a valid permutation and increment perm_i
bool isPermutation(int *arr, long int * const perm_i) {
  bool num_used[10] = {false};
  int * const end = arr + 10;
  
  while (arr < end) {
    if (num_used[*arr] == true) {
      return false;
    } else {
      num_used[*arr] = true;
      arr++;
    }
  }
  *perm_i += 1;
  return true;
}

// Print permutation
void printPerm(int *arr) {
  int * const end = arr + 10;
  while (arr < end) {
    printf("%i", *(arr++));
  }
  printf("\n");
}