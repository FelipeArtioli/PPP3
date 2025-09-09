// PPP - Chapter 3 - Exercise 6

#include <iostream>

using namespace std;

double calculation(char op, double a, double b) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    if (b == 0)
      return 0;
    else
      return a / b;
  default:
    return 0;
  }
}

string operation_name(char op) {
  switch (op) {
  case '+':
    return "sum";
  case '-':
    return "difference";
  case '*':
    return "product";
  case '/':
    return "ratio";
  default:
    return "invalid";
  }
}

int main() {
  double a{}, b{};
  char op{};

  cout << "Enter two numbers followed by an operator (e.g: 35.6 24.1 +):\n";

  while (cin >> a >> b >> op) {
    double result = calculation(op, a, b);
    string name = operation_name(op);

    if (op == '/' and b == 0) {
      cout << "Error: division by zero\n";
    } else if (name == "invalid") {
      cout << "Error: invalid operator\n";
    } else {
      cout << "The " << name << " of " << a << " and " << b << " is " << result
           << '\n';
    }
  }
}

// Write a program that performs as a very simple calculator. Your
// calculator should be able to handle the four basic math operations – add,
// subtract, multipla, and divide – on two input values. Your program
// should prompt the user to enter three arguments: two double values and a
// character to represent an operation. If the entry arguments are 35.6, 24.1,
// and '+', the program output should be The sum of 35.6 and 24.1 is 59.7. In
// Chapter 5 and Chapter 6, we look at a much more sophisticated simple
// calculator.
