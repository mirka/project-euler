#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(int n) {
  if (n < 4) return true;
  if (n % 2 == 0) return false;
  int end = floor(sqrt(n));

  int divisor = 3;
  do {
    if (n % divisor == 0) return false;
    divisor = divisor + 2;
  } while (divisor <= end);
  return true;
}

int sumOfRange(int start, int count, std::vector<int> array) {
  int bound = start + count;
  int sum = 0;
  for (int i = start; i < bound; i++) {
    sum += array[i];
  }
  return sum;
}

bool isIn(int n, std::vector<int> array) {
  for (int item : array) {
    if (n == item) return true;
  }
  return false;
}

int main() {
  std::vector<int> primes;

  for (int n = 2; n < 1000000; n++) {
    if (isPrime(n)) {
      primes.push_back(n);
    }
  }

  unsigned long count = primes.size();
  int maxTermCount = 21;
  int termCount = 0;
  int sum = 0;

  for (int i = 0; i < count - maxTermCount ; i++) {
    if (termCount == maxTermCount) break;

    for (termCount = maxTermCount; termCount < count - i; termCount++) {
      sum = sumOfRange(i, termCount, primes);
      if (sum > 1000000) break;
      if (isIn(sum, primes)) {
        std::cout << sum << " " << i << " " << termCount << std::endl;
        maxTermCount = termCount;
      }
    }
  }
  return 0;
}
