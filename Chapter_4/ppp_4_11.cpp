// PPP - Chapter 4 - 11
// Fibonacci sequence

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

vector<int> fib(int n) {

  vector<int> fibonacci = {};

  // Add values to vector
  if (n > 0)
    fibonacci.push_back(1);
  if (n > 1)
    fibonacci.push_back(1);

  for (int i = 2; i < n; ++i) {
    if (fibonacci[i - 1] > numeric_limits<int>::max() - fibonacci[i - 2]) {
      cout << "Next Fibonacci would overflow integer. Stopping.\n";
      break;
    }
    fibonacci.push_back(fibonacci[i - 2] + fibonacci[i - 1]);
  }
  return fibonacci;
}

void print(vector<int> fib) {
  cout << "Fibonacci sequence: ";
  for (int i = 0; i < fib.size(); ++i) {
    cout << fib[i] << " ";
  }
  cout << '\n';
}

int main() {

  cout << "Enter a number N to find the first N values of the Fibonacci "
          "series:\n";

  int n{};
  while (true) {
    cin >> n;
    // Checks for valid input
    if (!cin) {
      cerr << "Invalid input\n";
      return 1;
    }
    if (n <= 0) {
      cerr << "Please enter a positive number.\n";
      continue;
    } else
      // Generate ant print the sequence
      print(fib(n));
  }
}

// Write a program that writes out the first N values of the Fibonacci series,
// that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next number
// of the series is the sum of the two previous ones. Find the largest
// Fibonacci number that fits in an int.
