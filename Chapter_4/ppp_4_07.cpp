// PPP - Chapter 4 - 7
// Quadratic equation solver (With error handling and try/catch blocks)

#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

// Solve quadratic equation
void quadratic_equation(double a, double b, double c) {
  double delta = (b * b) - (4 * a * c);

  if (delta < 0) {
    // Negative discriminant == no real solutions
    throw runtime_error("Equation with no real roots");
  }

  double x1 = (-b + sqrt(delta)) / (2 * a);
  double x2 = (-b - sqrt(delta)) / (2 * a);

  cout << "x = " << x1 << " and x' = " << x2 << '\n';
}

// Print the quadratic equation in readable format
void print_result(double a, double b, double c) {
  cout << "Equation: ";

  // Print coefficient for x²
  if (a == 1)
    cout << "x²";
  else if (a == -1)
    cout << "-x²";
  else if (a != 0)
    cout << a << "x²";

  // Print coefficient for x
  if (b > 0) {
    if (b == 1)
      cout << "+x";
    else
      cout << "+" << b << "x";
  } else if (b < 0) {
    if (b == -1)
      cout << "-x";
    else
      cout << b << "x";
  }

  // Print constant term
  if (c > 0)
    cout << "+" << c;
  else if (c < 0)
    cout << c;

  cout << " = 0\n";
}

int main() {
  double a{}, b{}, c{};

  cout << "To solve a quadratic equation (ax²+bx+c=0), enter values for a, b "
          "and c:\n";

  cin >> a >> b >> c;

  // Validate input: 'a' cannot be zero, otherwise it's not quadratic
  if (a == 0) {
    cerr << "'a' cannot be zero in a quadratic equation.\n";
    return 1;
  }
  // Print equation in formatted way
  print_result(a, b, c);

  try {
    // Attempt to solve and print solutions
    quadratic_equation(a, b, c);
  } catch (exception &e) { // Catch "no real roots" or other runtime errors
    cerr << e.what() << '\n';
    return 2;
  }
}

// Quadratic equations are of the form a*x2 + b*x + c = 0. To solve these,
// one uses the quadratic formula: x = −b±√b 2 −4 ac. There is a problem,
// athough: if b2- 4ac is less than zero, then it will fail. Write a program
// that can calculate x for a quadratic equation. Create a function that prints
// out the roots of a quadratic equation, given a, b, c. When the program
// detects an equation with no real roots, have it print out a message. How
// do you know that your results are plausible? Can you check that they are
// correct?
