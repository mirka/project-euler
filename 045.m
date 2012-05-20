// After 40755, what is the next triangle number that is also pentagonal and hexagonal?

#import <Foundation/Foundation.h>

#define hex(n) (n) * (2 * (n) - 1)

int main (int argc, char *argv[]) {
  bool isTri(long n);
  bool isPent(long n);

  int h_n_end = 50000;
  long this_h;
  
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  
  for (int h_n = 144; h_n < h_n_end; h_n++) {
    this_h = hex(h_n);
    if (isTri(this_h) && isPent(this_h)) {
      NSLog(@"FOUND! %li", this_h);
    }
  }
  
  [pool drain];
  return 0;
}

// Returns whether integer n is triangular
bool isTri(long n) {
  double tri_root = (-1 + sqrt(8 * n + 1)) / 2;
  
  return tri_root == floor(tri_root) ? true : false;
}

// Returns whether integer n is pentagonal
bool isPent(long n) {
  double inv_n = (sqrt((24 * n) + 1) + 1) / 6;
  
  return inv_n == floor(inv_n) ? true : false;
}