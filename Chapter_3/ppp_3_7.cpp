// PPP - Chapter 3 - Exercise 7

#include <iostream>
#include <vector>
using namespace std;

bool is_digit(string input) {
  for (char c : input) {
    if (c < '0' or c > '9')
      return false;
  }
  return true;
}

string digit_to_spellout(string input, vector<string> numbers) {
  string result{};
  int index = stoi(input);
  if (index >= 0 and index < 10) {
    result = numbers[index];
  } else {
    result = "ERROR: unknown number.";
  }
  return result;
}

string spellout_to_digit(string input, vector<string> numbers) {
  string result{};
  for (int i = 0; i < 10; ++i) {
    if (input == numbers[i]) {
      result = to_string(i);
      return result;
      break;
    }
  }
  return "ERROR: unknown word.";
}

int main() {

  const vector<string> numbers = {"zero", "one", "two",   "three", "four",
                                  "five", "six", "seven", "eight", "nine"};

  cout << "Type a spelled-out number between zero-nine to get the digit.\n"
       << "Type a digit between 0-9 to get the spelled-out number.\n"
       << "Type exit to quit.\n";

  string input{};

  while (cin >> input) {
    if (input == "exit") {
      break;
    }
    bool digit_input = is_digit(input);
    if (digit_input) {
      cout << digit_to_spellout(input, numbers) << '\n';
    } else {
      cout << spellout_to_digit(input, numbers) << '\n';
    }
  }
}

// Make a vector holding the ten string values "zero", "one", . . . "nine".
// Use that in a program that converts a digit to its corresponding
// spelled-out value; e.g., the input 7 gives the output seven. Have the same
// program, using the same input loop, convert spelled-out numbers into their
// digit form; e.g., the input seven gives the output 7.
