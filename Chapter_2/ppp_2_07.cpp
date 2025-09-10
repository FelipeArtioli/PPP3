// PPP - Chapter 2 - Exercise 7
// Sort three words in alphabetical order

#include <iostream>
using namespace std;

int main() {
  string val_1{}, val_2{}, val_3{};
  cout << "Enter 3 words (or 0 0 0 to quit):\n";
  while (cin >> val_1 >> val_2 >> val_3) {
    if (val_1 == "0" and val_2 == "0" and val_3 == "0") {
      cout << "Good bye!\n";
      return 0;
    }
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

// Do exercise 6, but with three string values. So, if the user enters the
// values Steinbeck, Hemingway, Fitzgerald, the output should be Fitzgerald,
// Hemingway, Steinbeck.
