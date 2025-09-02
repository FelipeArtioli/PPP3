// PPP - Chapter 3 - Exercise 12

#include <iostream>
#include <vector>
using namespace std;

vector<int> primes = {2};

// Checks if a number is prime
bool is_prime(int x) {
  for (int i = 0; i < size(primes); ++i) {
    if (x % primes[i] == 0)
      return false;
  }
  return true;
}

// Prints a list of prime numbers in a range
void print_primes(int range) {
  int primes_size = size(primes);
  cout << "List of prime numbers from 2 to " << range << " : ";
  for (int j = 0; j < primes_size; ++j) {
    cout << primes[j];
    if (j == primes_size - 1)
      cout << ".\n";
    else
      cout << ", ";
  }
}

// Creates a vector with prime numbers
int main() {
  int range{100};
  for (int i = 3; i <= range; ++i) {
    if (is_prime(i)) {
      primes.push_back(i);
    }
  }
  print_primes(range);
}

// Create a program to find all the prime numbers between 1 and 100. One
// way to do this is to write a function that will check if a number is prime
// (i.e., see if the number can be divided by a prime number smaller than
// itself) using a vector of primes in order (so that if the vector is called
// primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a loop
// that goes from 1 to 100, checks each number to see if it is a prime, and
// stores each prime found in a vector. Write another loop that lists the
// primes you found. You might check your result by comparing your
// vector of prime numbers with primes. Consider 2 the first prime.
