// What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

#import <Foundation/Foundation.h>

int main (int argc, char *argv[]) {
  bool isGoldbach(long n);
  long nextOddComposite(long n);
  
  NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
  
  for (long comp = 9; comp < 10000; comp = nextOddComposite(comp)) {
    isGoldbach(comp);
  }
  
  [pool drain];
  return 0;
}

bool isPrime(long n) {
  int start;
  
  if (n <= 1) {
    return false;
  }
  
  start = sqrt(n);
  
  for (int i = 2; i <= start; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

// Returns the next odd composite number following odd number n
long nextOddComposite(long n) {
  bool isPrime(long n);
  
  do {
    n += 2;
  } while (isPrime(n));
  return n;
}

// Returns whether n can be written as the sum of a prime and twice a square
bool isGoldbach(long n) {
  bool isPrime(long n);
  long remainder;
  
  for (int i = 1; pow(i, 2) < n; i++) {
    remainder = n - (2 * pow(i, 2));
    if (isPrime(remainder)) {
//      NSLog(@"%li = %li + 2 * %i^2", n, remainder, i);
      return true;
    }
  }
  NSLog(@"NOT GOLDBACH: %li", n);
  return false;
}