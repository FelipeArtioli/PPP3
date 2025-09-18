// PPP - Chapter 3 - Exercise 13
// Sieve of Eratosthenes

#include <iostream>
#include <vector>
using namespace std;

// Vector to store found prime numbers
vector<int> primes = {};

// Generates primes up to 'range' using the sieve algorithm
void prime_generator(int range) {
  vector<bool> is_prime(range + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  // Mark multiples of each prime as non-prime
  for (int i = 2; i * i <= range; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= range; j += i) {
        is_prime[j] = false;
      }
    }
  }

  // Collect primes into the primes vector
  for (int i = 2; i < (range + 1); ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}

// Prints all primes up to 'range'
void print_primes(int range) {
  cout << "List of primes from 2 to " << range << ":\n";
  for (int i = 0; i < size(primes); ++i) {
    cout << primes[i];
    if (i == size(primes) - 1)
      cout << ".\n";
    else
      cout << ", ";
  }
}

int main() {
  int range{100};         // Max number to check
  prime_generator(range); // Generate primes
  print_primes(range);    // Display primes
}

// Create a program to find all the prime numbers between 1 and 100.
// There is a classic method for doing this, called the “Sieve of
// Eratosthenes.” If you don’t know that method, get on the Web and look
// it up. Write your program using this method.
