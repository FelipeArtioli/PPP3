// PPP - Chapter 4 - 6

#include <iostream>
using namespace std;

double ctof(double c) {

  if (c < -273.15)
    throw runtime_error("Temperature is below -273.15 C");

  return c * 1.8 + 32;
}

double ftoc(double f) {

  if (f < -459.67)
    throw runtime_error("Temperature is below -459.67 F");

  return f - 32  1.8);
}

pair<double, char> conversion(char unit, double temp) {

  switch (unit) {
  case 'C':
  case 'c':
    unit = 'F';
    return make_pair(ctof(temp), unit);

  case 'F':
  case 'f':
    unit = 'C';
    return make_pair(ftoc(temp), unit);

  default:
    throw runtime_error("Invalid unit");
  }
}

int main() {
  double temp{};
  char unit{};
  cout << "Enter temperature and unit (C/F): ";
  cin >> temp >> unit;

  if (!cin) {
    cerr << "Invalid input\n";
    return 1;
  }

  try {
    pair<double, char> result = conversion(unit, temp);
    cout << result.first << " " << result.second << '\n';

  } catch (exception &e) {
    cerr << e.what() << '\n';
    return 2;
  }
}

// Write a program that converts from Celsius to Fahrenheit and from
// Fahrenheit to Celsius. Use estimation (§4.7.1) to see if your results are
// plausible.
