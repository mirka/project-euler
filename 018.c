// Find the maximum sum travelling from the top of the triangle to the base.

#include <stdio.h>

int main () {
  void addFromRowBelow(int size, int r, int arr[size][size]);
  
  int size = 15;
  int arr[15][15] = {
    {75},
    {95, 64},
    {17, 47, 82},
    {18, 35, 87, 10},
    {20, 4, 82, 47, 65},
    {19, 1, 23, 75, 3, 34},
    {88, 2, 77, 73, 7, 63, 67},
    {99, 65, 4, 28, 6, 16, 70, 92},
    {41, 41, 26, 56, 83, 40, 80, 70, 33},
    {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
    {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
    {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
    {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
    {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
    {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
  };
  
  for (int i = size - 2; i >= 0; i--) {
    addFromRowBelow(size, i, arr);
  }
  
  printf("%i\n", arr[0][0]);
  
  return 0;
}

// To every number in row r of array, add the greatest adjacent number
// from the row below it
void addFromRowBelow(int size, int r, int arr[size][size]) {
  int *next_r = arr[r + 1];
  
  for (int i = 0; i <= r; i++) {
    arr[r][i] += (next_r[i] > next_r[i + 1]) ? next_r[i] : next_r[i + 1];
  }
}