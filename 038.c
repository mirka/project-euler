// What is the largest 1 to 9 pandigital that can be formed by multiplying a fixed number by 1, 2, 3, ... ?

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
  bool isPandigital(char *arr);
  
  char seq[20];
  char this_prod[10];
  unsigned long seq_len;
 
  for (int i = 2; i < 10000; i++) {
    sprintf(seq, "%i", i);
    
    for (int multiplier = 2; multiplier <= 5; multiplier++) {
      sprintf(this_prod, "%li", (long)i * multiplier);
      strcat(seq, this_prod);
      
      if ((seq_len = strlen(seq)) == 9 && isPandigital(seq)) {
        printf("FOUND! %i * 1 thru %i = %s\n", i, multiplier, seq);
      } else if (seq_len > 9) {
        break;
      }
    }
  }
  
  return 0;
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