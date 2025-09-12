// PPP - Chapter 4 - 12
// Bull and Cows (guessing game)

#include <iostream>
#include <vector>

using namespace std;

vector<char> curr_guess(char digit, vector<char> guess, int secret_size) {
  for (int i = 0; i < secret_size; ++i) {
    cin >> digit;
    guess[i] = digit;
  }
  return guess;
}

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
  return bull == secret.size();
}

int main() {

  vector<char> secret = {'1', '2', '3', '4'};
  int secret_size = secret.size();
  vector<char> guess = {'0', '0', '0', '0'};
  char digit{};
  bool game_wincon = false;

  while (!game_wincon) {
    guess = curr_guess(digit, guess, secret_size);
    game_wincon = found_bulls(guess, secret);
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
