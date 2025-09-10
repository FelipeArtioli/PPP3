// PPP - Chapter 2 - Exercise 6
// Sort three numbers in ascending order

#include <iostream>
using namespace std;

int main() {
  int val_1{}, val_2{}, val_3{};
  cout << "Enter 3 numbers (or 0 0 0 to quit):\n";
  while (cin >> val_1 >> val_2 >> val_3) {
    // Read three numbers in a loop

    if (val_1 == 0 and val_2 == 0 and val_3 == 0) {

      // Exit if all inputs are zero
      cout << "Good bye!\n";
      return 0;
    }
    //  Brute-force comparison extravaganza.
    if (val_1 <= val_2 and val_2 <= val_3) {
      cout << val_1 << ", " << val_2 << ", " << val_3 << '\n';
    } else if (val_1 <= val_3 and val_3 <= val_2) {
      cout << val_1 << ", " << val_3 << ", " << val_2 << '\n';
    } else if (val_2 <= val_1 and val_1 <= val_3) {
      cout << val_2 << ", " << val_1 << ", " << val_3 << '\n';
    } else if (val_2 <= val_3 and val_3 <= val_1) {
      cout << val_2 << ", " << val_3 << ", " << val_1 << '\n';
    } else if (val_3 <= val_1 and val_1 <= val_2) {
      cout << val_3 << ", " << val_1 << ", " << val_2 << '\n';
    } else {
      cout << val_3 << ", " << val_2 << ", " << val_1 << '\n';
    }
  }
  cout << "Good bye!\n";
}

// Write a program that prompts the user to enter three integer values, and
// then outputs the values in numerical sequence separated by commas. So,
// if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
// values are the same, they should just be ordered together. So, the input 4
// 5 4 should give 4, 4, 5.
