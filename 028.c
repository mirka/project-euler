// What is the sum of both diagonals in a 1001 by 1001 spiral?

#include <stdio.h>

int main () {
  int addRing(const int start, const int interval, long int *sum, long int end);
  
  long int end = 1001 * 1001;
  long int sum = 1;
  
  int diag_interval = 2;
  int ring_interval = 2;
  
  int exit_num = 1;
  
  while (exit_num < end) {
    exit_num = addRing(exit_num + diag_interval, ring_interval, &sum, end);
    diag_interval += 2;
    ring_interval += 2;
  }
  
  printf("Sum: %li\n", sum);
  
  return 0;
}



// Adds ring sum to *sum and returns exit number
int addRing(const int start, const int interval, long int *sum, long int end) {
  int this_num = start;
  
  *sum += this_num;
  
  for (int i = 0; i < 3; i++) {
    this_num += interval;
    *sum += this_num;
  }
  return this_num;
}