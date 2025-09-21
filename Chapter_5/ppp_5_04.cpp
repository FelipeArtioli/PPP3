// PPP - Chapter 5 - 4
// Store name-value pairs, check for duplicates, and search by score

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Class to hold a pair of name and score
class Name_value {

public:
  string name;
  int value;

  // Constructor initializes name and score
  Name_value(string s, int i) : name{s}, value{i} {}
};

// Checks for repeated names in the list
bool check_repetition(const vector<Name_value> &namescores) {

  // Sort by name before checking
  sort(
      namescores.begin(), namescores.end(),
      [](const Name_value &a, const Name_value &b) { return a.name < b.name; });

  for (int i = 1; i < namescores.size(); ++i) {
    if (namescores[i].name == namescores[i - 1].name) {
      cout << "ERROR: The name '" << namescores[i].name
           << "' was entered twice.\n";
      return true; // Duplicate found
    }
  }
  return false; // No duplicates
}

// Finds names that match a given score
void find_name(const vector<Name_value> &namescores) {

  int score{};
  // Continue reading scores until -1 is entered
  while (cin >> score && score != -1) {
    bool found = false;
    // Look for all names with the entered score
    for (const auto &nv : namescores) {
      if (nv.value == score) {
        cout << nv.name << '\n';
        found = true;
      }
    }
    // If no names were found, notify the user
    if (!found)
      cout << "Score not found.\n";
  }
}

int main() {

  vector<Name_value> namescores = {};

  string input_name{};
  int input_score{};

  cout << "Enter a set of name-and-value pairs, such as 'Joe 17'. Terminate "
          "input with 'NoName 0':\n";

  // Read name-score pairs until sentinel "NoName 0"
  while (cin >> input_name >> input_score) {
    if (input_name == "NoName" && input_score == 0)
      break;
    namescores.push_back(Name_value(input_name, input_score));
  }

  // Stop program if duplicate names were entered
  if (check_repetition(namescores))
    return 0;

  // Let user search for names by score
  cout << "Enter a score to find names with that score.\n"
       << "Enter '-1' to quit the program.\n";
  find_name(namescores);

  return 0;
}

// Define a class Name_value that holds a string and a value. Rework
// exercise 20 in Chapter 3 to use a vector<Name_value> instead of two
// vectors.
