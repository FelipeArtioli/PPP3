// PPP - Chapter 3 - Exercise 8
// Word/Digit Calculator

#include <iostream>
#include <vector>
using namespace std;

const vector<string> numbers = {"zero", "one", "two",   "three", "four",
                                "five", "six", "seven", "eight", "nine"};

// Perform arithmetic based on operator
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

// Return the name of the arithmetic operation
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

// Convert spelled-out number ("zero"-"nine") to digit string ("0"-"9")
string spellout_to_digit(string input, vector<string> numbers) {
  string result{};
  for (int i = 0; i < 10; ++i) {
    if (input == numbers[i]) {
      result = to_string(i);
      return result;
    }
  }
  return "ERROR";
}

// Check if string contains only digits
bool is_digit(string input) {
  for (char c : input) {
    if (c < '0' or c > '9')
      return false;
  }
  return true;
}

// Convert input string (digit or spelled-out) into a double
double string_to_double(string value) {

  bool digit_input = is_digit(value);
  if (digit_input) {
    return stoi(value); // direct conversion
  } else {
    if (spellout_to_digit(value, numbers) == "ERROR") { // invalid word
      return -1;
    } else {
      return stoi(spellout_to_digit(value, numbers));
    }
  }
}

int main() {

  double a{}, b{}, temp_a{}, temp_b{};
  string value_1{}, value_2{};
  char op{};

  cout << "Enter two numbers between 0-9 or zero-nine followed by an operator "
          "(e.g: three 2 +):\n";

  // Input loop
  while (cin >> value_1 >> value_2 >> op) {

    // Convert both inputs to numbers
    temp_a = string_to_double(value_1);
    temp_b = string_to_double(value_2);

    if (temp_a == -1 or temp_b == -1) {
      cout << "Error: unknown word\n";
      continue; // skip invalid input
    } else {
      a = temp_a;
      b = temp_b;
    }

    // Perform calculation
    double result = calculation(op, a, b);
    string name = operation_name(op);

    // Error handling
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

// Modify the “mini calculator” from exercise 6 to accept (just) single-digit
// numbers written as either digits or spelled out.
