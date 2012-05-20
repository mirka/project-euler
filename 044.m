// Find the smallest pair of pentagonal numbers whose sum and difference is pentagonal.

#import <Foundation/Foundation.h>

#define pent(n) ((n) * (3 * (n) - 1)) / 2

int main (int argc, char *argv[]) {
  bool areSumAndDiffPents(NSNumber *a, NSNumber *b, NSMutableArray *arr);
  
  int pent_arr_count = 10000;

  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  
  NSMutableArray *num_arr = [NSMutableArray arrayWithCapacity:pent_arr_count];
  NSNumber *this_pent;
  
  // Populate pentagonal number array
  for (int i = 0; i < pent_arr_count; i++) {
    this_pent = [NSNumber numberWithInteger:pent(i + 1)];
    [num_arr insertObject:this_pent atIndex:i];
  }
  
  for (int i = 1; i < pent_arr_count - 1; i++) {
    for (int j = i + 1; j < pent_arr_count; j++) {
      if (areSumAndDiffPents([num_arr objectAtIndex:i], [num_arr objectAtIndex:j], num_arr)) {
        break;
      }
    }
  }
  
  [pool drain];
  return 0;
}

// Returns whether integer n is pentagonal
bool isPent(long n) {
  float inv_n = (sqrt((24 * n) + 1) + 1) / 6;
  
  return inv_n == floor(inv_n) ? true : false;
}

// Returns true if both the sum and difference of two numbers are pentagonal
bool areSumAndDiffPents(NSNumber *a, NSNumber *b, NSMutableArray *arr) {
  bool isPent(long n);
  
  long a_val = [a integerValue];
  long b_val = [b integerValue];

  if (isPent(b_val - a_val) && isPent(a_val + b_val)) {
    NSLog(@"FOUND: %10li, %10li  DIFF: %10li", a_val, b_val, b_val - a_val);
    return true;
  }
  return false;
}