// PPP - Chapter 3 - Exercise 14

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes = {};

void prime_generator(int range) {
  vector<bool> is_prime(range + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i <= range; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= range; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 2; i < (range + 1); ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

void print_primes(int n) {
  cout << "List of the first " << n << " prime numbers:\n";
  for (int i = 0; i < n; ++i) {
    cout << primes[i];
    if (i == n - 1)
      cout << ".\n";
    else
      cout << ", ";
  }
}
int main() {
  cout << "Enter a value n to find the first n prime numbers:\n";
  int n{};
  int range{};
  while (true) {
    cin >> n;
    if (n < 0) {
      cout << "ERROR: Negative input.\n";
      break;
    }
    if (n >= 0 && n < 6)
      range = 15; // hardcoded value for small n
    else {
      range = n * (log(n) + log(log(n)));    // prime number theorem estimate
      range = static_cast<int>(range * 1.5); // safety margin
    }
    prime_generator(range);
    print_primes(n);
    cout << '\n';
  }
}

// Write a program that takes an input value n and then finds the first n
// primes.
