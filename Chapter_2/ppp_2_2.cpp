// PPP - Chapter 2 - Exercise 2

#include <iostream>
using namespace std;

int main() {
    constexpr double mile_to_km = 1.609;
    double miles{};
    
    cout << "Enter miles to convert to kilometers :\n";
    while (cin >> miles) {
        cout << miles << " miles = " << miles * mile_to_km << " kilometers.\n";
    }
}

// Write a program in C++ that converts from miles to kilometers. Your
// program should have a reasonable prompt for the user to enter a number
// of miles. Hint: A mile is 1.609 kilometers.
