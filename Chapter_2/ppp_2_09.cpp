// PPP - Chapter 2 - Exercise 9
// Convert a spelled-out number (zero to four) to a digit

#include <iostream>
using namespace std;

int main() {
  string input{};
  cout << "Enter a spelled-out number from zero to four:\n";
  cin >> input;

  // Match input to known words and print digit, or show error
  if (input == "zero")
    cout << "0\n";
  else if (input == "one")
    cout << "1\n";
  else if (input == "two")
    cout << "2\n";
  else if (input == "three")
    cout << "3\n";
  else if (input == "four")
    cout << "4\n";
  else
    cout << "Not a number I know.\n";
}

// Write a program that converts spelled-out numbers such as “zero” and
// “two” into digits, such as 0 and 2. When the user inputs a number, the
// program should print out the corresponding digit. Do it for the values 0,
// 1, 2, 3, and 4 and write out not a number I know if the user enters
// something that doesn’t correspond, such as stupid computer!.
