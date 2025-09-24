// PPP - Chapter 4 - 5
// Add ktoc() to C to K converter

#include <iostream>
using namespace std;

// Convert Celsius to Kelvin
double ctok(double c) {

  if (c < -273.15) // Absolute zero in Celsius
    throw runtime_error("Temperature is below -273.15 C");

  return c + 273.15; // Formula: K = C + 273.15
}

// Convert Kelvin to Celsius
double ktoc(double k) {

  if (k < 0) // Kelvin cannot be negative
    throw runtime_error("Temperature is below 0 K");

  return k - 273.15; // Formula: C = K - 273.15
}

// Perform conversion based on input unit
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

  if (!cin) { // check for bad input
    cerr << "Invalid input\n";
    return 1;
  }

  try {
    // Convert and print result
    pair<double, char> result = conversion(unit, temp);
    cout << result.first << " " << result.second << '\n';

  } catch (exception &e) {
    cerr << e.what() << '\n';
    return 2;
  }
}

// Add to the program so that it can also convert from Kelvin to Celsius.
