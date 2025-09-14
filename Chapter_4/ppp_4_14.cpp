// PPP - Chapter 4 - 14
// Day-of-week value collector

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Lowercase a string
string to_lower(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

// Return index of weekday (0..6), or -1 if invalid
int day_to_index(string s) {
  string day_input = to_lower(s);
  vector<string> days = {"monday", "tuesday",  "wednesday", "thursday",
                         "friday", "saturday", "sunday"};

  for (int i = 0; i < days.size(); ++i) {
    if (day_input == days[i])
      return i; // full name
    if (day_input.size() == 3 && day_input == days[i].substr(0, 3))
      return i; // 3-letter abbrev
  }
  return -1; // not valid
}

int main() {
  vector<string> days_pretty = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                                "Friday", "Saturday", "Sunday"};

  vector<vector<int>> values(7); // one vector<int> for each weekday
  string day{};
  int value{};
  int rejected{};

  cout << "Enter a sequence of (day-of-the-week, value) pairs:\n"
          " e.g: Tuesday 23 Friday 56 Tuesday -3\n"
          "Press Ctrl+D (or Ctrl+Z on Windows) to end input.\n\n";

  while (cin >> day >> value) {
    int index = day_to_index(day);

    if (index == -1) {
      cout << "Ignored invalid day: " << day << '\n';
      ++rejected;
    } else {
      values[index].push_back(value);
    }
  }

  cout << "\nResults:\n";
  for (int i = 0; i < days_pretty.size(); ++i) {
    cout << days_pretty[i] << ": ";
    int sum{};
    for (int v : values[i]) {
      cout << v << " ";
      sum += v;
    }
    cout << "| sum = " << sum << '\n';
  }

  cout << "\nRejected entries: " << rejected << '\n';
}

// Read (day-of-the-week,value) pairs from standard input. For example:
// Tuesday 23 Friday 56 Tuesday −3 Thursday 99
// Collect all the values for each day of the week in a vector<int>. Write out
// the values of the seven day-of-the-week vectors. Print out the sum of the
// values in each vector. Ignore illegal days of the week, such as Funday,
// but accept common synonyms such as Mon and monday. Write out the
// number of rejected values.
