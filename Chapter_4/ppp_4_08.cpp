// PPP - Chapter 4 - 8
// Sum the first N integers from user input

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

int sum_values(vector<int> values, int n) {
  // Check if we have enough values
  if (n > values.size())
    throw runtime_error("Amount of integers is too small");
  int sum{};
  for (int i = 0; i < n; ++i) {
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

// Write a program that reads and stores a series of integers and then
// computes the sum of the first N integers. First ask for N, then read the
// values into a vector, then calculate the sum of the first N values. For
// example:
// Please enter the number of values you want to sum: 3
// Please enter some integers (press ’|’ to stop): 12 23 13 24 15 |
// The sum of the first 3 numbers ( 12 23 13 )is 48
// Handle all inputs. For example, make sure to give an error message if
// the user asks for a sum of more numbers than there are in the vector.
