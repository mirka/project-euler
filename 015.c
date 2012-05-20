// Starting in the top left corner in a 20 by 20 grid, how many routes are there to the bottom right corner?

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main () {
  double latticePaths(const int n);
  double factorial(int n);
  
  printf("%f\n", latticePaths(20));
    
  return 0;
}

// Calculate the central binomial coefficient
double latticePaths(const int n) {
  double factorial(int n);
  
  return (factorial(2 * n)) / pow(factorial(n), 2);
}


// Calculate factorial of n
double factorial(int n) {
  double product = 1;
  
  while (n > 0) {
    product *= n--;
  }
  return product;
}


//// Below are the naive implementations that didn't work

// Count routes on grid of size n, starting from node {r, c}
void bruteCountRoutes(const int size, const int r, const int c,
                      long int *count) {
  
  if (r == size && c == size) { // reached an edge
    *count += 1;
  }
  
  if (r < size) {
    bruteCountRoutes(size, (r + 1), c, count);
  }
  if (c < size) {
    bruteCountRoutes(size, r, (c + 1), count);
  }
}

long int routeCount(const int grid_size) {
  bool incrementDigit(int arr[], int i, int limit);
  
  long int count = 1;
  int lastdigit_i = grid_size - 1;
  int arr[grid_size];
  
  // Initialize array
  for (int i = 0; i < grid_size; i++) {
    arr[i] = 0;
  }
  
  while (incrementDigit(arr, lastdigit_i, grid_size) == true) {
    count++;
  }
  
  return count;
}

// Increment the i-th digit of a digit array.
// Carries over when necessary
bool incrementDigit(int arr[], int i, int limit) {
  if (i == 0 && arr[0] == limit) { // reached max value
    return false;
  } else if (arr[i] == limit) { // carry over to preceeding digit
    if (incrementDigit(arr, i - 1, limit) == false) { // reached max value
      return false;
    } else {
      arr[i] = arr[i - 1];
      return true;
    }
  } else {
    arr[i]++;
    return true;
  }
}