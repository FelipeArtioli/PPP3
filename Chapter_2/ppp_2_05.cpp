// PPP - Chapter 2 - Exercise 5
// Compare two doubles and show basic math operations

#include <iostream>
using namespace std;

int main() {
  double val1{}, val2{};
  cout << "Enter two double values:\n";
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
      // Doubles keep the decimal part when dividing.
    }
  }
}

// Modify the program above to ask the user to enter floating-point values
// and store them in double variables. Compare the outputs of the two
// programs for some inputs of your choice. Are the results the same?
// Should they be? What’s the difference?
