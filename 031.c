// Investigating combinations of English currency denominations.

#include <stdio.h>
#include <stdbool.h>

int main() {
  bool isLastPerm(int perm[]);
  void makePerm(int i, int perm[], int units[]);
  void printPerm(int *perm);
  
  int units[] = {200, 100, 50, 20, 10, 5, 2};
  int perm[7] = {0};
  
  int i = 0;
  
  int rev_i;
  
  while (true) {
    makePerm(i, perm, units);
    printPerm(perm);
    
    while (perm[6] != 0)  {
      perm[6]--;
      printPerm(perm);

      if (isLastPerm(perm)) {
        return 0;
      }
    }
    
    for (rev_i = 6; perm[rev_i] == 0; rev_i--) {
    }
    
    perm[rev_i]--;
    i = rev_i + 1;
  };
  
  
  return 0;
}

// Checks whether end condition is met
bool isLastPerm(int perm[]) {
  for (int i = 0; i < 7; i++) {
    if (perm[i] != 0) {
      return false;
    }
  }
  return true;
}

// Generates permutation starting with unit index i
void makePerm(int i, int perm[], int units[]) {
  int amountLeft(int *perm, int *units, const int limit);
  int maxCoinsIn(const int value, const int sum);
  
  int amount_left;
  
  while ((amount_left = amountLeft(perm, units, 200)) > 0 &&
         i < 7) {
    perm[i] = maxCoinsIn(units[i], amount_left);
    i++;
  }
  
}

// Returns maximum number of coins with value to make sum
int maxCoinsIn(const int value, const int sum) {
  return (int)sum / value;
}

// Returns amount left until limit of a permutation
int amountLeft(int *perm, int *units, const int limit) {
  int sum = 0;
  
  for (int i = 0; i < 7; i++) {
    sum += *perm * *units;
    perm++;
    units++;
  }
  return limit - sum;
}


// Prints permutation
void printPerm(int *perm) {
  static int count = 0;
  
  count++;
  printf("%3i: ", count);
  
  for (int i = 0; i < 7; i++) {
    printf("%i ", *perm);
    perm++;
  }
  printf("\n");
}