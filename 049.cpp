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

bool couldBePerm(int x, int y) {
  return (y - x) % 9 == 0;
}

bool isIn(int n, std::vector<int> array) {
  unsigned long length = array.size();
  for (int i = 0; i < length && n <= array[length - 1]; i++) {
    if (array[i] == n) return true;
  }
  return false;
}

int sumDigits(int n) {
  int digit;
  int sum = 0;
  while (n) {
    digit = n % 10;
    sum += digit;
    n /= 10;
  }
  return sum;
}

bool remove(int digit, std::vector<int> &digits) {
  for (int i = 0; i < digits.size(); i++) {
    if (digits[i] == digit) {
      digits.erase(digits.begin() + i);
      return true;
    }
  }
  return false;
}

bool isPerm(int x, int y, int z) {
  int digit;
  std::vector<int> digits1;
  std::vector<int> digits2;

  for (int i = 0; i < 4; i++) {
    digit = x % 10;
    digits1.push_back(digit);
    digits2.push_back(digit);
    x /= 10;
  }
  for (int i = 0; i < 4; i++) {
    digit = y % 10;
    if (!remove(digit, digits1)) return false;
    y /= 10;
  }
  for (int i = 0; i < 4; i++) {
    digit = z % 10;
    if (!remove(digit, digits2)) return false;
    z /= 10;
  }
 return true;
}

int main() {
  std::vector<int> primes;

  for (int n = 1000; n < 9999; n++) {
    if (isPrime(n)) {
      primes.push_back(n);
    }
  }

  int diff, target;

  for (int i = 0; i < primes.size(); i++) {
    for (int j = i + 1; j < primes.size(); j++) {
      if (couldBePerm(primes[i], primes[j])) {
        diff = primes[j] - primes[i];
        target = primes[j] + diff;

        if (target > primes[primes.size() - 1]) continue;

        if (
            isIn(target, primes) &&
            isPerm(primes[i], primes[j], target)
            ) {
          std::cout << primes[i] << " " << primes[j] << " " << target <<std::endl;
        }
      }
    }

  }
  return 0;
}

