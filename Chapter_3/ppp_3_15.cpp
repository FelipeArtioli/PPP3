// PPP - Chapter 3 - 15

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers = {};
  int curr_count{1}, max_count{1}, mode{};
  int input{};
  while (cin >> input) {
    if (input >= 0)
      numbers.push_back(input);
  }
  sort(numbers.begin(), numbers.end());
  for (int i = 1; i < numbers.size(); ++i) {
    if (numbers[i] == numbers[i - 1]) {
      ++curr_count;
      if (curr_count > max_count) {
        max_count = curr_count;
        mode = numbers[i];
      }
    } else {
      curr_count = 1;
    }
  }
  if (max_count == 1)
    cout << "No mode found (all numbers are unique).\n";
  else
    cout << "Mode: " << mode << " (appeared " << max_count << " times)\n";
}

// In the drill, you wrote a program that, given a series of numbers, found
// the max and min of that series. The number that appears the most times
// in a sequence is called the mode. Create a program that finds the mode
// of a set of positive integers.
