// PPP - Chapter 3 - Drill

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<double> value;
double temp{}, converted_temp{}, smaller{}, larger{};
string unit{};

double convert_to_meters(string unit) {

  double convertion{};

  if (unit == "m") {
    convertion = 1.0;
  } else if (unit == "cm") {
    convertion = 1.0 / 100;
  } else if (unit == "in") {
    convertion = 1.0 * (2.54 / 100);
  } else if (unit == "ft") {
    convertion = 12.0 * (2.54 / 100);
  } else {
    convertion = 0;
  }
  return convertion;
}

void smaller_or_larger(double smaller, double larger) {

  if (temp * convert_to_meters(unit) == smaller) {
    cout << "\n--> " << temp * convert_to_meters(unit)
         << " m is the SMALLEST value.\n";
  }
  if (temp * convert_to_meters(unit) == larger) {
    cout << "\n--> " << temp * convert_to_meters(unit)
         << " m is the LARGEST value.\n";
  }
}

int main() {
  cout << "\nEnter a value (float) followed by a unit (string: 'm', 'cm', 'in' "
          "or 'ft'):";
  cout << "\ne.g.: '10 m', '25 ft', '17 in', etc.\n\n";

  int i = 0;
  while (cin >> temp >> unit) {
    if (convert_to_meters(unit) == 0) {
      cout << "ERROR: invalid unit\n";
    } else {
      value.push_back(temp * convert_to_meters(unit));

      if (i == 0) {
        smaller = value[i];
        larger = value[i];
      }
      if (value[i] < smaller) {
        smaller = value[i];
      }
      if (value[i] > larger) {
        larger = value[i];
      }
      if (unit == "m") {
        ;
      } // Do nothing
      else {
        cout << temp << " " << unit << " = " << temp * convert_to_meters(unit)
             << " m\n";
      }

      smaller_or_larger(smaller, larger);

      sort(value.begin(), value.end());

      cout << "\nValues: ";
      for (int j = 0; j <= i; ++j) {
        cout << value[j] << " | ";
      }
      cout << "\n";

      double sum{};
      for (double x : value) {
        sum += x;
      }
      cout << "Total: " << sum << " m" << "\n\n";

      ++i;
    }
  }
}

// Go through this drill step by step. Do not try to speed up by skipping steps.
// Test each step by entering at least three pairs of values – more values would
// be better.
// [1] Write a program that consists of a while-loop that (each time around
// the loop) reads in two ints and then prints them. Exit the program
// when a terminating '|' is entered.
// [2] Change the program to write out the smaller value is: followed by the
// smaller of the numbers and the larger value is: followed by the larger
// value.
// [3] Augment the program so that it writes the line the numbers are equal
// (only) if they are equal.
// [4] Change the program so that it uses doubles instead of ints.
// [5] Change the program so that it writes out the numbers are almost equal
// after writing out which is the larger and the smaller if the two
// numbers differ by less than 1.0/100.
// [6] Now change the body of the loop so that it reads just one double each
// time around. Define two variables to keep track of which is the
// smallest and which is the largest value you have seen so far. Each
// time through the loop write out the value entered. If it’s the smallest
// so far, write the smallest so far after the number. If it is the largest so
// far, write the largest so far after the number.
// [7] Add a unit to each double entered; that is, enter values such as 10cm,
// 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. Assume
// conversion factors 1m==100cm, 1in==2.54cm, 1ft==12in. Read the unit
// indicator into a string. You may consider 12 m (with a space between
// the number and the unit) equivalent to 12m (without a space).
// [8] Reject values without units or with “illegal” representations of units,
// such as y, yard, meter, km, and gallons.
// [9] Keep track of the sum of values entered (as well as the smallest and
// the largest) and the number of values entered. When the loop ends,
// print the smallest, the largest, the number of values, and the sum of
// values. Note that to keep the sum, you have to decide on a unit to use
// for that sum; use meters.
// [10] Keep all the values entered (converted into meters) in a vector. At the
// end, write out those values.
// [11] Before writing out the values from the vector, sort them (that’ll make
// them come out in increasing order).
