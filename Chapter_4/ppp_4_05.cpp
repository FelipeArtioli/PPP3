// PPP - Chapter 4 - 5

#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

double ctok(double c) {

  if (c < -273.15)
    throw runtime_error("Temperature is below -273.15 C");

  return c + 273.15;
}

double ktoc(double k) {

  if (k < 0)
    throw runtime_error("Temperature is below 0 K");

  return k - 273.15;
}

pair<double, char> conversion(char unit, double temp) {

  switch (unit) {
  case 'C':
  case 'c':
    unit = 'K';
    return make_pair(ctok(temp), unit);

  case 'K':
  case 'k':
    unit = 'C';
    return make_pair(ktoc(temp), unit);

  default:
    throw runtime_error("Invalid unit");
  }
}

int main() {
  double temp{};
  char unit{};
  cout << "Enter temperature and unit (C/K): ";
  cin >> temp >> unit;

  if (!cin) {
    cerr << "Invalid input\n";
    return 0;
  }

  try {
    pair<double, char> result = conversion(unit, temp);
    cout << result.first << " " << result.second << '\n';

  } catch (exception &e) {
    cerr << e.what() << '\n';
    return 1;
  }
}

// Add to the program so that it can also convert from Kelvin to Celsius.
