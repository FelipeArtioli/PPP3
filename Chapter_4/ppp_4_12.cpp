// PPP - Chapter 4 - 12
// Bull and Cows (guessing game)

#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Read and validate a guess from the user
vector<int> guess(vector<int> secret) {

  vector<int> guess = {};
  string input{};
  cin >> input;

  for (char c : input) {
    // Validate input is a digit
    if (c <= '/' || c >= ':') {
      throw runtime_error("Only digits are allowed");
    }
    // Validate input length
    if (input.size() != secret.size()) {
      throw runtime_error("Too many or too few digits");
    }
    // Convert char digit to int
    guess.push_back(c - '0');
  }
  return guess;
}

// Compare guess to secret and count bulls and cows
bool found_bulls(vector<int> guess, vector<int> secret) {

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
  // Return true if all digits are bulls
  return bull == secret.size();
}

int main() {

  vector<int> secret = {1, 2, 3, 4};
  int secret_size = secret.size();
  bool game_wincon = false;

  cout << "Enter your " << secret.size() << "-digit guess:\n";

  while (!game_wincon) {
    try {
      game_wincon = found_bulls(guess(secret), secret);
    } catch (exception &e) {
      cerr << e.what() << '\n';
    }
  }
  cout << "Congratulations, you won!\n";
}

//  Implement a little guessing game called (for some obscure reason)
// “Bulls and Cows.” The program has a vector of four different integers in
// the range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to
// discover those numbers by repeated guesses. Say the number to be
// guessed is 1234 and the user guesses 1359; the response should be “1
// bull and 1 cow” because the user got one digit (1) right and in the right
// position (a bull) and one digit (3) right but in the wrong position (a
// cow). The guessing continues until the user gets four bulls, that is, has
// the four digits correct and in the correct order.
