// PPP - Chapter 3 - 20
// Score to name lookup

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Check if any name was entered more than once
bool check_repetition(vector<string> names) {

  sort(names.begin(), names.end()); // Sort names alphabetically
  for (int i = 1; i < names.size(); ++i) {
    if (names[i] == names[i - 1]) { // Duplicate found
      cout << "ERROR: The name '" << names[i] << "' was entered twice.\n";
      return true;
    }
  }
  return false; // No duplicates
}
// Find and print all names associated with a given score
void find_name(vector<string> names, vector<int> scores) {

  int score{};
  while (cin >> score) { // Read scores from user
    if (score == -1)     // Sentinel to stop querying
      break;
    bool found = false;

    // Search for all names matching the score
    for (int i = 0; i < names.size(); ++i) {
      if (score == scores[i]) {
        cout << names[i] << '\n';
        found = true;
      }
    }
    if (!found) // No names matched
      cout << "Score not found.\n";
  }
}

int main() {

  vector<string> names = {}; // Store entered names
  string input_name{};       // Store corresponding scores
  vector<int> scores = {};
  int input_score{};
  cout << "Enter a set of name-and-value pairs, such as 'Joe 17'. Terminate "
          "input with 'NoName 0':\n";

  // Read name-score pairs from the user
  while (cin >> input_name >> input_score) {
    if (input_name == "NoName" && input_score == 0) // Sentinel to stop input
      break;
    names.push_back(input_name);
    scores.push_back(input_score);
  }

  // Check for duplicate names
  if (check_repetition(names))
    return 0;

  cout << "Enter a score to find names with that score.\n"
       << "Enter '-1' to quit the program.\n";

  // Allow user to query all names matching a score
  find_name(names, scores);

  return 0;
}

// Modify the program from the previous exercise so that once you have
// entered the name-and-value pairs, you ask for names: In a loop, when
// you enter a value, the program will output all the names with that score
// or score not found.
