// PPP - Chapter 3 - Exercise 10
//Chessboard Rice Problem (part 2)

#include <iostream>
using namespace std;

int main() {
  unsigned long long grains_on_square{1};
  unsigned long long total_grains{};
  constexpr int board_size{64};

  cout << "Square:" << "\t\t" << "Gifted grains:" << '\n';

  for (int i = 1; i <= board_size; ++i) {
    total_grains += grains_on_square;             // Add grains from this square
    cout << i << "\t\t" << total_grains << "\n";  // Show progress
    grains_on_square *= 2;                        // Double grains for next square
  }
}

// Try to calculate the number of rice grains that the inventor asked for in
// exercise 9 above. You’ll find that the number is so large that it won’t fit
// in an int or a double. Observe what happens when the number gets too
// large to represent exactly as an int and as a double. What is the largest
// number of squares for which you can calculate the exact number of
// grains (using an int)? What is the largest number of squares for which
// you can calculate the approximate number of grains (using a double)
