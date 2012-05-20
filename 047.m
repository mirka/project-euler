// Find the first four consecutive integers to have four distinct primes factors.

#import <Foundation/Foundation.h>

int main (int argc, char *argv[]) {
  int dpfCount(long n);

  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  
  int consec_target = 4;
  int consec_count = 0;

  
  for (long i = 14; i < 1000000; i++) {
    if (dpfCount(i) == consec_target) {
      consec_count++;
    } else {
      consec_count = 0;
    }
    
    if (consec_count == consec_target) {
      NSLog(@"Found! %li", i);
      break;
    }
  }
      
  [pool drain];
  return 0;
}

bool isPrime(long n) {
  int last;
  
  if (n <= 1) {
    return false;
  }
  
  last = sqrt(n);
  
  for (int i = 2; i <= last; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// Returns the number of distinct prime factors of n
int dpfCount(long n) {
  bool isPrime(long n);
  long firstPrimeFactor(long n);
  
  NSMutableArray *dpf_arr = [NSMutableArray arrayWithCapacity:2];
  NSNumber *this_factor;
  NSNumber *remainder;
  
  while (isPrime(n) == false) {
    this_factor = [NSNumber numberWithLong:firstPrimeFactor(n)];
    
    if ([dpf_arr containsObject:this_factor] == false) {
      [dpf_arr addObject:this_factor];
    }
    n /= this_factor.longValue;
  }
  
  remainder = [NSNumber numberWithLong:n];
  
  if ([dpf_arr containsObject:remainder] == false) {
    [dpf_arr addObject:remainder];
  }

  return (int)[dpf_arr count];
}

// Return first prime factor of n
long firstPrimeFactor(long n) {
  int last = sqrt(n);
  
  for (int f = 2; f <= last; f++) {
    if (n % f == 0) {
      return f;
    }
  }
  return n;
}