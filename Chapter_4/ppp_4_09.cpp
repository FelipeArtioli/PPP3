// PPP - Chapter 4 - 9
// Sum the first N integers from user input with overflow/underflow checks

#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

using namespace std;

int sum_values(vector<int> values, int n) {
  // Check if we have enough values
  if (n > values.size())
    throw runtime_error("Amount of integers is too small");
  int sum{};
  for (int i = 0; i < n; ++i) {
    // Check for overflow before adding
    if (sum > numeric_limits<int>::max() - values[i]) {
      throw runtime_error("Overflow: result too large for int");
    }
    // Check for underflow before adding
    if (sum < numeric_limits<int>::min() + values[i]) {
      throw runtime_error("Underflow: result too small for int");
    }
    sum += values[i];
  }
  return sum;
}

void print_result(vector<int> values, int n, int result) {
  cout << "The sum of the first " << n << " numbers ( ";
  for (int i = 0; i < n; ++i) {
    cout << values[i] << " ";
  }
  cout << ") is: " << result << '\n';
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

  cout << "Please enter some integers (press '|' to stop):\n";
  vector<int> values = {};
  int number{};
  while (cin >> number) {
    values.push_back(number);
  }

  try {
    int result = sum_values(values, n);
    print_result(values, n, result);
  } catch (exception &e) {
    cerr << e.what() << '\n';
    return 2;
  }
}

// Modify the program from the previous exercise to write out an error if
// the result cannot be represented as an int.
