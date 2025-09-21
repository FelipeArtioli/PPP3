// PPP - Chapter 3 - 19
// Name and Score Lookup (user can query scores by name)

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

// Find and print the score corresponding to a given name
void find_score(vector<string> names, vector<int> scores) {

  string name{};
  while (cin >> name) {
    if (name == "exit")
      break;
    bool found = false;
    for (int i = 0; i < names.size(); ++i) {
      if (name == names[i]) {
        cout << scores[i] << '\n';
        found = true;
        break;
      }
    }
    if (!found)
      cout << "Name not found.\n";
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
    if (input_name == "NoName" && input_score == 0)
      break;
    names.push_back(input_name);
    scores.push_back(input_score);
  }

  // Check for duplicate names
  if (check_repetition(names))
    return 0;

  cout << "Enter a name to find its score.\n"
       << "Enter 'exit' to quit the program.\n";

  // Allow the user to query scores by name
  find_score(names, scores);

  return 0;
}

// Modify the program from the previous exercise so that once you have
// entered the name-and-value pairs, you ask for values: In a loop, when
// you enter a name, the program will output the corresponding score or
// name not found.
