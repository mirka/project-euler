// If p is the perimeter of a right angle triangle, {a, b, c}, which value, for p ≤ 1000, has the most solutions?

#include <stdio.h>
#include <math.h>

#define sq(n) pow(n, 2)

int main () {
  int max_a, max_b;
  int c;
  int solutions, max_solutions = 0;
  int max_when_p;
  
  for (int p = 6; p <= 1000; p++) { // perimeter (a + b + c)
    solutions = 0;
    max_a = (p - 3) / 3;
    
    for (int a = 1; a <= max_a; a++) {
      max_b = (p - a - 1) / 2;
      
      for (int b = a + 1; b <= max_b; b++) {
        c = p - a - b;
        
        if (sq(a) + sq(b) == sq(c)) {
          solutions++;
        }
      }
    }
    
    if (solutions > max_solutions) {
      max_solutions = solutions;
      max_when_p = p;
    }
  }
  
  printf("Max %i solutions when p = %i\n", max_solutions, max_when_p);
  
  return 0;
}