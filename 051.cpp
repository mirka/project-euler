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

bool isIn(int n, std::vector<int> array) {
  if (n > array[array.size() - 1]) return false;

  for (int item : array) {
    if (n == item) return true;
  }
  return false;
}

bool diffDigitsAreSame(int x, int y, std::vector<int> &position) {
  int digitX, digitY, diffDigit = 0;
  bool hadDiffDigit = false;
  int diffDigitX = 0;
  int i = 0;
  while (x) {
    digitX = x % 10;
    digitY = y % 10;
    if (digitX != digitY) {
      if (hadDiffDigit && (diffDigit != digitY || diffDigitX != digitX)) return false;
      hadDiffDigit = true;
      diffDigit = digitY;
      diffDigitX = digitX;
      position.push_back(i);
    }
    x /= 10;
    y /= 10;
    i++;
  }
  return true;
}

std::vector<int> matches(int n, std::vector<int> positions, std::vector<int> pool) {
  std::vector<int> results = {n};
  int diff = 0;
  while (positions.size()) {
    int position = positions[positions.size() - 1];
    diff += pow(10, position);
    positions.pop_back();
  }
  for (int multiplier = 1; multiplier < 10; multiplier++) {
    int target = n + (diff * multiplier);
    if (!diffDigitsAreSame(n, target, positions)) break;
    if (isIn(target, pool)) results.push_back(target);
  }
  return results;
}

int main() {
  std::vector<int> primes;
  std::vector<int> positions;
  std::vector<int> results;

  for (int n = 100000; n < 1000000; n++) {
    if (isPrime(n)) {
      primes.push_back(n);
    }
  }

  int count = 8;
  for (int i = 0; i < primes.size() - count; i++) {
    for (int j = i + 1; j < primes.size(); j++) {
      positions.clear();
      if (diffDigitsAreSame(primes[i], primes[j], positions)) {
        results = matches(primes[i], positions, primes);
        if (results.size() == count) {
          std::cout << results[0] << std::endl;
        }
      }
    }
  }
  return 0;
}
