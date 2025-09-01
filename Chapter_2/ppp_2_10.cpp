// PPP - Chapter 2 - Exercise 10

#include <iostream>
using namespace std;

int main() {

  double val_1{}, val_2{}, result{};
  string operation{};

  cout << "Enter an operator followed by two values:\n"
       << "Enter 'exit' to quit.\n\n";

  while (true) {
    cin >> operation;
    if (operation == "exit") {
      break;
    }
    cin >> val_1 >> val_2;

    if (operation == "+" or operation == "plus") {
      result = val_1 + val_2;
    } else if (operation == "-" or operation == "minus") {
      result = val_1 - val_2;
    } else if (operation == "*" or operation == "mul") {
      result = val_1 * val_2;
    } else if (operation == "/" or operation == "div") {
      if (val_2 == 0) {
        cout << "ERROR: Division by zero.\n";
        continue;
      } else {
        result = val_1 / val_2;
      }
    } else {
      cout << "ERROR: Invalid operator\n";
      continue;
    }
    cout << result << '\n';
  }
  cout << "Good bye!\n";
}

// Write a program that takes an operation followed by two operands and
// outputs the result. For example:
// + 100 3.14
// * 45
// Read the operation into a string called operation and use an if-statement
// to figure out which operation the user wants, for example, if
// (operation=="+"). Read the operands into variables of type double.
// Implement this for operations called +, −, *, /, plus, minus, mul, and div
// with their obvious meanings.
