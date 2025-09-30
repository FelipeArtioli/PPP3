// PPP - Chapter 4 - 6
// Celsius-Fahrenheit Temperature Converter

#include <iostream>
using namespace std;

// Convert Celsius to Fahrenheit
double ctof(double c) {

  if (c < -273.15) // Below absolute zero in Celsius
    throw runtime_error("Temperature is below -273.15 C");

  return c * 1.8 + 32; // Formula: F = C × 1.8 + 32
}

// Convert Fahrenheit to Celsius
double ftoc(double f) {

  if (f < -459.67) // Below absolute zero in Fahrenheit
    throw runtime_error("Temperature is below -459.67 F");

  return (f - 32) / 1.8; // Formula: C = (F − 32) ÷ 1.8
}

// Decide which conversion to apply based on input unit
pair<double, char> conversion(char unit, double temp) {

  switch (unit) {
  case 'C': // Celsius (uppercase)
  case 'c': // Celsius (lowercase)
    unit = 'F';
    return make_pair(ctof(temp), unit);

  case 'F': // Fahrenheit (uppercase)
  case 'f': // Fahrenheit (lowercase)
    unit = 'C';
    return make_pair(ftoc(temp), unit);

  default: // Input unit not recognized
    throw runtime_error("Invalid unit");
  }
}

int main() {
  double temp{};
  char unit{};
  cout << "Enter temperature and unit (C/F): ";
  cin >> temp >> unit;

  if (!cin) { // Check for input failure
    cerr << "Invalid input\n";
    return 1;
  }

  try {
    // Convert and display result
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
