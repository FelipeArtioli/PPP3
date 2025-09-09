// PPP - Chapter 3 - Exercise 9

#include <iostream>
using namespace std;

int main() {
  int least_amount{};
  int grains_on_square{1};
  int total_grains{};
  constexpr int board_size{64};

  cout << "Type the least amount of rice grains to gift the inventor: ";
  cin >> least_amount;
  cout << '\n';

  cout << "Square:" << "\t\t" << "Gifted grains:" << '\n';

  for (int i = 1; total_grains <= least_amount and i <= board_size; ++i) {
    total_grains += grains_on_square;
    cout << i << "\t\t" << total_grains << "\n";
    grains_on_square *= 2;
  }
}

// There is an old story that the emperor wanted to thank the inventor of the
// game of chess and asked the inventor to name his reward. The inventor
// asked for one grain of rice for the first square, 2 for the second, 4 for
// the third, and so on, doubling for each of the 64 squares. That may sound
// modest, but there wasn’t that much rice in the empire! Write a program
// to calculate how many squares are required to give the inventor at least
// 1000 grains of rice, at least 1,000,000 grains, and at least 1,000,000,000
// grains. You’ll need a loop, of course, and probably an int to keep track
// of which square you are at, an int to keep the number of grains on the
// current square, and an int to keep track of the grains on all previous
// squares. We suggest that you write out the value of all your variables for
// each iteration of the loop so that you can see what’s going on.
