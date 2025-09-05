// PPP - Chapter 3 - 18

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> names, vector<int> scores) {
  for (int i = 0; i < names.size(); ++i) {
    cout << names[i] << ": " << scores[i] << '\n';
  }
  cout << '\n';
}

bool check_repetition(vector<string> names) {
  sort(names.begin(), names.end());
  for (int i = 1; i < names.size(); ++i) {
    if (names[i] == names[i - 1]) {
      cout << "ERROR: The name '" << names[i] << "' was entered twice.\n";
      return true;
    }
  }
  return false;
}

int main() {

  vector<string> names = {};
  string input_name{};
  vector<int> scores = {};
  int input_score{};
  cout << "Enter a set of name-and value pairs, such as 'Joe 17'. Terminate "
          "input with 'NoName 0':\n";
  while (cin >> input_name >> input_score) {
    if (input_name == "NoName" && input_score == 0)
      break;
    names.push_back(input_name);
    scores.push_back(input_score);
  }

  if (check_repetition(names))
    return 0;

  cout << '\n';
  print(names, scores);
}

// Write a program where you first enter a set of name-and-value pairs,
// such as Joe 17 and Barbara 22. For each pair, add the name to a vector
// called names and the number to a vector called scores (in corresponding
// positions, so that if names[7]=="Joe" then scores[7]==17). Terminate input
// with NoName 0. Check that each name is unique and terminate with an
// error message if a name is entered twice. Write out all the (name,score)
// pairs, one per line.
