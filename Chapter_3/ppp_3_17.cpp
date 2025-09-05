// PPP - Chapter 3 - 17

#include <cmath>
#include <iostream>
using namespace std;

void quadratic_equation(double a, double b, double c) {
  double delta = (b * b) - (4 * a * c);

  if (delta < 0) {
    cout << "No real solutions (delta < 0).\n";
    return;
  }

  double x1 = (-b + sqrt(delta)) / (2 * a);
  double x2 = (-b - sqrt(delta)) / (2 * a);

  cout << "x = " << x1 << " and x' = " << x2 << '\n';
}
void print_result(double a, double b, double c) {
  cout << "Equation: " << a << "x²";
  if (b >= 0)
    cout << "+" << b << "x";
  else
    cout << b << "x";
  if (c >= 0)
    cout << "+" << c;
  else
    cout << c;
  cout << " = 0\n";
}

int main() {
  double a{}, b{}, c{};

  cout << "To solve a quadratic equation (ax²+bx+c=0), enter values for a, b "
          "and c:\n";
  cin >> a;

  if (a == 0) {
    cout << "'a' cannot be zero in a quadratic equation.\n";
    return 0; // stop immediately
  }

  cin >> b >> c;
  print_result(a, b, c);
  quadratic_equation(a, b, c);
}

// Write a program to solve quadratic equations. A quadratic equation is of
// the form ax² + bx + c = 0. If you don’t know the formula for solving
// such an expression, do some research. Remember, researching how to
// solve a problem is often necessary before a programmer can teach the
// computer how to solve it. Use doubles for the user inputs for a, b, and c.
// Since there are two solutions to a quadratic equation, output both x1 and
// x2.
