// PPP - Chapter 3 - Exercise 11
// Simple Rock-Paper-Scissors Game

#include <iostream>
#include <vector>
using namespace std;

// Decides the winner given machine's move (m) and player's move (p)
string game_logic(char m, char p) {
  if (m == p)
    return "TIE!";
  else if ((m == 'r' and p == 's') or (m == 'p' and p == 'r') or
           (m == 's' and p == 'p'))
    return "YOU LOSE!";
  else
    return "YOU WON!";
}

// Converts move character to full word for display
string char_to_string(char c) {
  switch (c) {
  case 'r':
    return "ROCK";
  case 'p':
    return "PAPER";
  case 's':
    return "SCISSORS";
  default:
    return "INVALID";
  }
}

int main() {
  // Predefined machine moves
  vector<char> machine_moves = {'r', 'p', 'r', 's', 's', 'p', 'r', 'r',
                                'p', 'p', 'r', 's', 'p', 's', 'p', 'r',
                                'r', 's', 'p', 'r', 's', 'p'};

  cout << "\nEnter rock, paper or scissors (r,p,s) or 'q' to quit:\n";

  int i{};
  while (true) {
    char player_value{};
    cin >> player_value;

    if (player_value == 'q') // Exit game
      break;

    switch (player_value) {
    case 'r':
    case 'p':
    case 's': {
      // Get machine's move based on current index
      char machine_value = machine_moves[i];
      // Convert moves to strings for nicer display
      string machine_string = char_to_string(machine_value);
      string player_string = char_to_string(player_value);
      // Decide result
      string result = game_logic(machine_value, player_value);
      // Show round outcome
      cout << "Machine played " << machine_string << " and you played "
           << player_string << '\n';
      cout << result << '\n';
      break;
    }
    default:
      cout << "Invalid input. Please enter 'r', 'p', or 's'.\n";
    }
    // Cycle through machine moves (wraps back to start)
    i = (i + 1) % machine_moves.size();
  }

  cout << "Thanks for playing!\n";
}

// Write a program that plays the game “Rock, Paper, Scissors.” Use a switch-
// statement to solve this exercise. Also, the machine should give random
// answers (i.e., select the next rock, paper, or scissors randomly). Real
// randomness is too hard to provide just now, so just build a vector with a
// sequence of values to be used as “the next value.” If you build the vector
// into the program, it will always play the same game, so maybe you
// should let the user enter some values. Try variations to make it less easy
// for the user to guess which move the machine will make next.
