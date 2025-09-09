// PPP - Chapter 3 - Exercise 4

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  cout << "Enter a sequence of values(double):\n";

  vector<double> distance = {};
  double sum{};
  double mean{};
  double smaller{}, larger{};
  double value{};

  for (int i = 0; cin >> value; i++) {
    sum += value;
    distance.push_back(value);
  }
  mean = sum / distance.size();

  sort(distance.begin(), distance.end());
  smaller = distance[0];
  larger = distance[distance.size() - 1];

  cout << "The sum is: " << sum << '\n';
  cout << "The mean is: " << mean << '\n';
  cout << "The smaller is: " << smaller << '\n';
  cout << "The larger is: " << larger << '\n';
}

// Read a sequence of double values into a vector. Think of each value as the
// distance between two cities along a given route. Compute and print the
// total distance (the sum of all distances). Find and print the smallest and
// greatest distance between two neighboring cities. Find and print the
// mean distance between two neighboring cities.
