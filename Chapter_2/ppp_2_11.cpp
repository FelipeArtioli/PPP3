// PPP - Chapter 2 - Exercise 10

#include <iostream>
using namespace std;

int main() {

  int pennies{}, nickels{}, dimes{}, quarters{}, halves{}, dollars{};

  string plural_pennies{}, plural_nickels{}, plural_dimes{}, plural_quarters{},
      plural_halves{}, plural_dollars{};

  cout << "How many pennies do you have? ";
  cin >> pennies;
  cout << "How many nickels do you have? ";
  cin >> nickels;
  cout << "How many dimes do you have? ";
  cin >> dimes;
  cout << "How many quarters do you have? ";
  cin >> quarters;
  cout << "How many half dollars do you have? ";
  cin >> halves;
  cout << "How many dollars do you have? ";
  cin >> dollars;

  if (pennies != 1)
    plural_pennies = "pennies";
  else
    plural_pennies = "penny";
  if (nickels != 1)
    plural_nickels = "nickels";
  else
    plural_nickels = "nickel";
  if (dimes != 1)
    plural_dimes = "dimes";
  else
    plural_dimes = "dime";
  if (quarters != 1)
    plural_quarters = "quarters";
  else
    plural_quarters = "quarter";
  if (halves != 1)
    plural_halves = "half dollars";
  else
    plural_halves = "half dollar";
  if (dollars != 1)
    plural_dollars = "dollars";
  else
    plural_dollars = "dollar";

  int total = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * halves +
              100 * dollars;
  int only_dollars = total / 100;
  int only_cents = total % 100;

  cout << "\nYou have " << pennies << " " << plural_pennies << ".\n";
  cout << "You have " << nickels << " " << plural_nickels << ".\n";
  cout << "You have " << dimes << " " << plural_dimes << ".\n";
  cout << "You have " << quarters << " " << plural_quarters << ".\n";
  cout << "You have " << halves << " " << plural_halves << ".\n";
  cout << "You have " << dollars << " " << plural_dollars << ".\n";
  cout << "The value of all your coins is " << only_dollars << ".";
  if (only_cents < 10)
    cout << "0";
  cout << only_cents << " dollars.\n";
}

// Write a program that prompts the user to enter some number of pennies
// (1-cent coins), nickels (5-cent coins), dimes (10-cent coins), quarters
// (25-cent coins), half dollars (50-cent coins), and one-dollar coins (100-
// cent coins). Query the user separately for the number of each size coin,
// e.g., “How many pennies do you have?” Then your program should
// print out something like this:
// Click here to view code image
// You have 23 pennies.
// You have 17 nickels.
// You have 14 dimes.
// You have 7 quarters.
// You have 3 half dollars.
// The value of all of your coins is 573 cents.
// Make some improvements: if only one of a coin is reported, make the
// output grammatically correct, e.g., 14 dimes and 1 dime (not 1 dimes).
// Also, report the sum in dollars and cents, i.e., .73 instead of 573 cents.
