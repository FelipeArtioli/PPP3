// PPP - Chapter 3 - Exercise 5

#include <iostream>

using namespace std;

int main() {
  int min_number{1}, max_number{100};

  cout << "Think of a number between 1 and 100.\n"
       << "Answer the questions with y for yes or n for no.\n\n"
       << "Press Enter to start...\n";

  cin.ignore(); // Wait for user input

  while (min_number < max_number) {
    int mid = min_number + (max_number - min_number) / 2;

    cout << "Is your number <= " << mid << "? (y/n): ";
    char answer{};
    cin >> answer;

    switch (answer) {
    case 'y': case 'Y':
      max_number = mid;
      break;
    case 'n': case 'N':
      min_number = mid + 1;
      break;
    default:
      cout << "Please answer with 'y' or 'n'.\n";
      break;
    }
  }

  cout << "\aYour number is " << min_number << "!\n";
}

// Write a program to play a numbers guessing game. The user thinks of a
// number between 1 and 100 and your program asks questions to figure
// out what the number is (e.g., “Is the number you are thinking of less
// than 50?”). Your program should be able to identify the number after
// asking no more than seven questions.
