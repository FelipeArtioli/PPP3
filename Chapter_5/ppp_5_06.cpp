// PPP - Chapter 5 - 6
// Bull and Cows (now with letters)

#include <algorithm>
#include <cctype>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Read and validate a guess from the user
vector<char> guess(vector<char> secret) {

  vector<char> guess = {};
  string input{};
  cin >> input;

  // Validate input length
  if (input.size() != secret.size()) {
    throw runtime_error("Too many or too few characters");
  }
  for (char c : input) {
    // Validate input is a letter
    if (!isalpha(c))
      throw runtime_error("Only letters are allowed");

    // Uppercase the letter and push to vector
    guess.push_back(toupper(c));
  }
  return guess;
}

// Compare guess to secret and count bulls and cows
bool found_bulls(vector<char> guess, vector<char> secret) {

  int bull{}, cow{};

  for (int i = 0; i < secret.size(); ++i) {

    bool is_bull = false;

    if (guess[i] == secret[i]) {
      ++bull;
      is_bull = true;

    } else
      for (int j = 0; j < secret.size(); ++j) {
        if (guess[i] == secret[j] && (!is_bull)) {
          ++cow;
        }
      }
  }

  cout << bull << " bull and " << cow << " cow\n";
  // Return true if all letters are bulls
  return bull == secret.size();
}

int main() {

  vector<char> secret = {'A', 'B', 'C', 'D'};
  bool game_wincon = false;

  cout << "Enter your " << secret.size() << "-letter guess:\n";

  while (!game_wincon) {
    try {
      game_wincon = found_bulls(guess(secret), secret);
    } catch (exception &e) {
      cerr << e.what() << '\n';
    }
  }
  cout << "Congratulations, you won!\n";
}

// Redo the “Bulls and Cows” game from exercise 12 in Chapter 4 to use
// four letters rather than four digits.
