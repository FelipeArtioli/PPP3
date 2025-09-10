// PPP - Chapter 4 - 4

#include <iostream>
using namespace std;

double ctok(double c) {

  if (c < -273.15)
    throw runtime_error("Temperature is below -273.15C or 0K");

  return c + 273.15;
}

int main() {
  double c = 0;
  cin >> c;

  try {

    auto k = ctok(c);
    cout << k << '\n';

  } catch (exception &e) {

    cerr << e.what() << '\n';
    return 1;
  }
}

// Do exercise 3 again, but this time handle the error inside ctok().
