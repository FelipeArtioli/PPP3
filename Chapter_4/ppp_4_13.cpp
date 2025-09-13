// PPP - Chapter 4 - 13
// Bull and Cows (now using random numbers)

#include <exception>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

using namespace std;

// Generates pseudorandom numbers with the Mersenne Twister algorithm
int random_gen(int min, int max) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(min, max);
  int random_value{distrib(gen)};
  return random_value;
}

// Check if a number is already in the vector
bool already_in(vector<int> secret, int num) {
  for (int d : secret) {
    if (d == num)
      return true;
  }
  return false;
}

// Generate a 4-digit secret with unique digits
vector<int> gen_secret() {
  vector<int> secret;
  int max_digits{4};

  while (secret.size() < max_digits) {
    int temp = random_gen(0, 9);
    if (!already_in(secret, temp)) {
      secret.push_back(temp);
    }
  }

  return secret;
}

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

  bool keep_playing = true;
  while (keep_playing) {

    vector<int> secret = gen_secret();
    int secret_size = secret.size();

    cout << "Enter your " << secret.size() << "-digit guess:\n";

    bool game_wincon = false;
    while (!game_wincon) {
      try {
        game_wincon = found_bulls(guess(secret), secret);
      } catch (exception &e) {
        cerr << e.what() << '\n';
      }
    }
    cout << "Congratulations, you won!\n"
            "Type y to play again.\n";

    char yorn{};
    cin >> yorn;
    if (yorn == 'y' || yorn == 'Y')
      keep_playing = true;
    else
      keep_playing = false;
  }
}

// The program is a bit tedious because the answer is hard-coded into the
// program. Make a version where the user can play repeatedly (without
// stopping and restarting the program) and each game has a new set of
// four digits. You can get four random digits by calling the random
// number generator random_int(0,9) from PPP_support (and §4.7.5) four
// times. You will note that if you run that program repeatedly, it will pick
// the same sequence of four digits each time you start the program. To
// avoid that, ask the user to enter a number (any number) and call seed(n),
// also from PPP_support, where n is the number the user entered before
// calling random_int(0,10). Such an n is called a seed, and different seeds
// give different sequences of random numbers.
