// PPP - Chapter 3 - Exercise 13

#include <iostream>
#include <vector>
using namespace std;

int main() {

  int range{100};
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
  vector<int> primes = {};
  for (int i = 0; i < (range + 1); ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
  for (int i = 0; i < size(primes); ++i) {
    cout << primes[i] << ", ";
  }
}

// Create a program to find all the prime numbers between 1 and 100.
// There is a classic method for doing this, called the “Sieve of
// Eratosthenes.” If you don’t know that method, get on the Web and look
// it up. Write your program using this method.
