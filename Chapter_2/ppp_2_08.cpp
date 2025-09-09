// PPP - Chapter 2 - Exercise 8

#include <iostream>
using namespace std;

int main() {
  int input{};
  cout << "Enter a number to test if they are even or odd: ";
  cin >> input;
  if (!cin) {
    cout << "ERROR: Invalid input.\n";
    return 0;
  }
  if (input % 2 == 0)
    cout << input << " is an even number.\n";
  else
    cout << input << " is an odd number.\n";
}

// Write a program to test an integer value to determine if it is odd or even.
// As always, make sure your output is clear and complete. In other words,
// don’t just output yes or no. Your output should stand alone, like The
// value 4 is an even number. Hint: See the remainder (modulo) operator in
// §2.4.
