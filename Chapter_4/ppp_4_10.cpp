// PPP - Chapter 4 - 10

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

double sum_values(vector<double> values, int n) {
  // Check if we have enough values
  if (n > values.size())
    throw runtime_error("Amount of doubles is too small");
  double sum{};
  for (int i = 0; i < n; ++i) {
    sum += values[i];
  }
  return sum;
}

void print_result(vector<double> values, int n, double result) {
  cout << "The sum of the first " << n << " numbers ( ";
  for (int i = 0; i < n; ++i) {
    cout << values[i] << " ";
  }
  cout << ") is: " << result << '\n';
}

vector<double> differences(vector<double> values, int n) {
  vector<double> diffs = {};
  for (int i = 1; i < n; ++i) {
    diffs.push_back(values[i] - values[i - 1]);
  }
  return diffs;
}

void print_diffs(vector<double> diffs) {
  cout << "The differences between adjacent numbers are: ";
  for (int i = 0; i < diffs.size(); ++i) {
    cout << diffs[i] << " ";
  }
  cout << '\n';
}

int main() {

  // Ask user how many values to sum, must be positive
  int n{};
  cout << "Please enter the number of values you want to sum: ";
  cin >> n;
  if (!cin || n <= 0) {
    cerr << "Number must be positive\n";
    return 1;
  }

  cout << "Please enter some doubles (press '|' to stop):\n";
  vector<double> values = {};
  double number{};
  while (cin >> number) {
    values.push_back(number);
  }

  try {
    double result = sum_values(values, n);
    print_result(values, n, result);
  } catch (exception &e) {
    cerr << e.what() << '\n';
    return 2;
  }
  print_diffs(differences(values, n));
}

// Modify the program from the previous exercise to use double instead of
// int. Also, make a vector of doubles containing the N-1 differences
// between adjacent values and write out that vector of differences.
