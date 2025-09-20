// PPP - Chapter 3 - 16
// Find min, max, and mode of a set of strings

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Sort words alphabetically
vector<string> sort_words(vector<string> words) {
  sort(words.begin(), words.end());
  return words;
}

// Find the mode
string find_mode(vector<string> words) {
  int curr_count{1}, max_count{1};
  string mode{};
  for (int i = 1; i < words.size(); ++i) {
    if (words[i] == words[i - 1]) {
      ++curr_count;
      if (curr_count > max_count) {
        max_count = curr_count;
        mode = words[i];
      }
    } else {
      curr_count = 1;
    }
  }
  if (max_count == 1)
    return ""; // "no mode"
  else
    return mode;
}

int main() {
  vector<string> words = {};
  string input{};
  cout << "Enter a set of strings to find the min, max and mode of the set:\n";

  // Read words
  while (cin >> input) {
    words.push_back(input);
  }

  if (words.empty()) {
    cout << "No words entered.\n";
    return 0;
  }

  // Sort and find mode
  words = sort_words(words);
  string mode = find_mode(words);
  string min = words[0];
  string max = words[words.size() - 1];
  // Print results
  cout << "Max = " << max << '\n';
  cout << "Min = " << min << '\n';
  if (mode.empty())
    cout << "No mode found (all words are unique).\n";
  else
    cout << "Mode = " << mode << '\n';
}

// Write a program that finds the min, max, and mode of a sequence of
// strings.
