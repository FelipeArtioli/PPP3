// PPP - Chapter 5 - 8

#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

long long factorial(int x) {
  if (x < 0)
    throw runtime_error("Factorial not defined for negative numbers.");
  long long result = 1;
  for (int i = 2; i <= x; ++i) {
    result *= i;
  }
  return result;
}

long long permutation(int a, int b) {
  if (b > a)
    throw runtime_error("b cannot be larger than a for permutations.");
  return factorial(a) / factorial(a - b);
}

long long combination(int a, int b) {
  if (b > a)
    throw runtime_error("b cannot be larger than a for combinations.");
  return permutation(a, b) / factorial(b);
}

// Read an integer
int read_int(const string &prompt) {
  int x;
  cout << prompt;
  while (!(cin >> x) || x <= 0) {
    cout << "Please enter a positive integer: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  return x;
}

int main() {
  try {
    int a = read_int("Enter the first number (a): ");
    int b = read_int("Enter the second number (b): ");

    cout << "Permutation (p) or Combination (c)? ";
    char choice;
    cin >> choice;

    switch (tolower(choice)) {
    case 'p':
      cout << "P(" << a << ", " << b << ") = " << permutation(a, b) << '\n';
      break;
    case 'c':
      cout << "C(" << a << ", " << b << ") = " << combination(a, b) << '\n';
      break;
    default:
      cout << "Invalid choice. Please enter 'p' or 'c'.\n";
    }
  } catch (exception &e) {
    cerr << "Error: " << e.what() << '\n';
    return 1;
  }
}

// A permutation is an ordered subset of a set. For example, say you
// wanted to pick a combination to a vault. There are 60 possible numbers,
// and you need three different numbers for the combination. There are
// P(60, 3) permutations for the combination, where P is defined by the
// formula P(a, b) = (a!) / ((a - b)!) where ! is used as a suffix factorial
// operator. For example, 4! is 4*3*2*1.
// Combinations are similar to permutations, except that the order of
// the objects doesn’t matter. For example, if you were making a
// “banana split” sundae and wished to use three different flavors of ice
// cream out of five that you had, you probably wouldn’t care if you put
// a scoop of vanilla at the beginning or the end or the serving dish. The
// formula for combinations is C(a, b) = (P(a, b)) / (b!)
// Design a program that asks users for two numbers, asks them
// whether they want to calculate permutations or combinations, and
// prints out the result. This will have several parts. Do an analysis of the
// above requirements. Write exactly what the program will have to do.
// Then, go into the design phase. Write pseudo code for the program
// and break it into subcomponents. This program should have error
// checking. Make sure that all erroneous inputs will generate good error
// messages.
