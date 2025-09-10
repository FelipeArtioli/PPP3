// PPP - Chapter 4 - 3

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
  if (c < -273.15) {
    cerr << "ERROR: Temperature is below -273.15C, or 0K.\n";
    return 1;
  }
  double k = ctok(c);
  // declare input variable
  // retrieve temperature to input variable
  // convert temperature
  cout << k << '\n';
  // print out temperature
}

// Absolute zero is the lowest temperature that can be reached; it is
// -273.15C, or 0K. The above program, even when corrected, will
// produce erroneous results when given a temperature below this. Place a
// check in the main program that will produce an error if a temperature is
// given below -273.15C.
