// PPP - Chapter 4 - 2

#include <iostream>
using namespace std;

double ctok(double c) {
  double k = c + 273.15;
  return k;
}
// converts Celsius to Kelvin
int main() {
  double c = 0;
  cin >> c;
  double k = ctok(c);
  // declare input variable
  // retrieve temperature to input variable
  // convert temperature
  cout << k << '\n';
  // print out temperature
}

// The following program takes in a temperature value in Celsius and
// converts it to Kelvin. This code has many errors in it. Find the errors,
// list them, and correct the code.
