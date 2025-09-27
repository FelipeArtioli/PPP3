// PPP - Chapter 5 - 7

#include <cctype>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class Token {
  int value;
  int position;

public:
  static const vector<string> kinds;

  Token(int v, int pos) : value{v}, position{pos} {
    if (v < 0 || v > 9)
      throw runtime_error("Invalid digit");
  }

  bool isZero() const { return value == 0; }

  string toString() const {
    string unit = kinds[position];
    if (value == 1 && unit.back() == 's') { // Plural rule
      unit.pop_back();
    }
    return to_string(value) + " " + unit;
  }
};

const vector<string> Token::kinds = {"ones", "tens", "hundreds", "thousands"};

// Generate a vector of tokens
vector<Token> gen_tokens(const string &input) {
  if (input.size() > Token::kinds.size())
    throw runtime_error("Inputs of this size are not supported.");

  vector<Token> tokens;
  int n = input.size();

  for (int i = 0; i < n; ++i) {
    char c = input[i];
    if (!isdigit(c))
      throw runtime_error("Only digits are allowed");

    int digit = c - '0';
    int pos = n - i - 1;

    Token t(digit, pos);
    if (!t.isZero()) // Skip zeroes
      tokens.push_back(t);
  }
  return tokens;
}

// Print in a formatted way
void print(const vector<Token> &tokens) {
  for (int i = 0; i < tokens.size(); ++i) {
    cout << tokens[i].toString();
    if (i != tokens.size() - 1)
      cout << " and ";
  }
}

int main() {
  string input;
  while (cin >> input) {
    try {
      vector<Token> tokens = gen_tokens(input);
      print(tokens);
      cout << '\n';
    } catch (const exception &e) {
      cerr << e.what() << '\n';
    }
  }
}

// Write a program that reads digits and composes them into integers. For
// example, 123 is read as the characters 1, 2, and 3. The program should
// output 123 is 1 hundred and 2 tens and 3 ones. The number should be output
// as an int value. Handle numbers with one, two, three, or four digits.
// Hint: To get the integer value 5 from the character '5' subtract '0', that
// is, '5'−'0'==5.
