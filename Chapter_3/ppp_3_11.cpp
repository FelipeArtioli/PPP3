// PPP - Chapter 3 - Exercise 11

#include <iostream>
using namespace std;

char machine_turn(int a, int b, int c) {
  if (a < b)
    return 'r';
  if (b > a)
    return 'p';
  if (c < a)
    return 's';
  return 'p';
}

string game_logic(char m, char p) {
  if (m == p)
    return "TIE!";
  if ((m == 'r' and p == 's') or (m == 'p' and p == 'r') or
      (m == 's' and p == 'p'))
    return "YOU LOSE!";
  return "YOU WON!";
}

string char_to_string(char c) {
  switch (c) {
  case 'r':
    return "ROCK";
  case 'p':
    return "PAPER";
  case 's':
    return "SCISSORS";
  default:
    return 0;
  }
}

int main() {

  char player_value{};
  string player_string{};
  char machine_value{};
  string machine_string{};
  int value1{}, value2{}, value3{};
  string game_result{};

  cout << "Enter 3 values: \n";
  cin >> value1 >> value2 >> value3;
  machine_value = machine_turn(value1, value2, value3);
  cout << "\nEnter rock, paper or scissors (r,p,s): \n";
  cin >> player_value;
  game_result = game_logic(machine_value, player_value);
  machine_string = char_to_string(machine_value);
  player_string = char_to_string(player_value);
  cout << "Machine played " << machine_string
       << " and you played " << player_string << '\n';
  cout << game_result << '\n';
}

// Write a program that plays the game “Rock, Paper, Scissors.” Use a switch-
// statement to solve this exercise. Also, the machine should give random
// answers (i.e., select the next rock, paper, or scissors randomly). Real
// randomness is too hard to provide just now, so just build a vector with a
// sequence of values to be used as “the next value.” If you build the vector
// into the program, it will always play the same game, so maybe you
// should let the user enter some values. Try variations to make it less easy
// for the user to guess which move the machine will make next.
