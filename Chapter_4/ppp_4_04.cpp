// PPP - Chapter 4 - 4

#include <iostream>
using namespace std;

void error(string error) { throw runtime_error{error}; }

double ctok(double c) {

  if (c < 273.15)
    error("Temperature is below -273.15C or 0K\n");

  double k = c + 273.15;
  return k;
}

// converts Celsius to Kelvin
int main() {
  double c = 0;
  cin >> c;

  try {
    double k = ctok(c);
    // declare input variable
    // retrieve temperature to input variable
    // convert temperature
    cout << k << '\n';
    // print out temperature
  } catch (exception &e) {
    cerr << e.what() << '\n';
    return 1;
  }
}

// Do exercise 3 again, but this time handle the error inside ctok().
