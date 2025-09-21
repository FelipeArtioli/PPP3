// PPP - Chapter 3 - 17
// Quadratic Equation Solver

#include <cmath>
#include <iostream>
using namespace std;

// Solve quadratic equation and print the real solutions if they exist
void quadratic_equation(double a, double b, double c) {
  // Calculate discriminant (b² - 4ac)
  double delta = (b * b) - (4 * a * c);
  // If delta is negative, no real solutions exist
  if (delta < 0) {
    cout << "No real solutions (delta < 0).\n";
    return;
  }
  // Compute both roots using quadratic formula
  double x1 = (-b + sqrt(delta)) / (2 * a);
  double x2 = (-b - sqrt(delta)) / (2 * a);

  cout << "x = " << x1 << " and x' = " << x2 << '\n';
}

// Print the equation in a readable mathematical form
void print_result(double a, double b, double c) {
  cout << "Equation: ";

  // Handle coefficient of x²
  if (a == 1)
    cout << "x²";
  else if (a == -1)
    cout << "-x²";
  else if (a != 0)
    cout << a << "x²";
  // Handle coefficient of x
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
  // Handle constant term
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

  // Read coefficients from user
  cin >> a >> b >> c;
  // Quadratic equations require a ≠ 0
  if (a == 0) {
    cout << "'a' cannot be zero in a quadratic equation.\n";
    return 0;
  }
  // Show the formatted equation
  print_result(a, b, c);
  // Solve and display solutions
  quadratic_equation(a, b, c);
}

// Write a program to solve quadratic equations. A quadratic equation is of
// the form ax² + bx + c = 0. If you don’t know the formula for solving
// such an expression, do some research. Remember, researching how to
// solve a problem is often necessary before a programmer can teach the
// computer how to solve it. Use doubles for the user inputs for a, b, and c.
// Since there are two solutions to a quadratic equation, output both x1 and
// x2.
