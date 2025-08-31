// PPP - Chapter 2 - Exercise 4

#include <iostream>
using namespace std;

int main() {
  int val1{}, val2{};
  cout << "Enter two integer values:\n";
  while (cin >> val1 >> val2) {
    if (val1 == val2) {
      cout << val1 << " and " << val2 << " are equal.\n";
    } else if (val1 < val2) {
      cout << val1 << " is the smaller.\n" << val2 << " is the larger.\n";
    } else {
      cout << val2 << " is the smaller.\n" << val1 << " is the larger.\n";
    }
    cout << val1 << " + " << val2 << " = " << val1 + val2 << '\n';
    cout << val1 << " - " << val2 << " = " << val1 - val2 << '\n';
    cout << val1 << " * " << val2 << " = " << val1 * val2 << '\n';
    if (val2 == 0) {
      cout << "Division by zero is impossible.\n\n";
    } else {
      cout << val1 << " / " << val2 << " = " << val1 / val2 << "\n\n";
    }
  }
}

// Write a program that prompts the user to enter two integer values. Store
// these values in int variables named val1 and val2. Write your program to
// determine the smaller, larger, sum, difference, product, and ratio of
// these values and report them to the user.
