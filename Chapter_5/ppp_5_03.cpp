// PPP - Chapter 5 - 3
// Add factorial to the calculator

#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

//------------------ functions replacing std_lib_facilities.h ------------------

void error(string s) { throw runtime_error(s); }

inline void keep_window_open() {
  cin.clear();
  cout << "Please enter a character to exit\n";
  char ch;
  cin >> ch;
  return;
}

inline void keep_window_open(string s) {
  if (s == "")
    return;
  cin.clear();
  cin.ignore(120, '\n');
  for (;;) {
    cout << "Please enter " << s << " to exit\n";
    string ss;
    while (cin >> ss && ss != s)
      cout << "Please enter " << s << " to exit\n";
    return;
  }
}

//------------------------------------------------------------------------------

class Token {
public:
  char kind;     // what kind of token
  double value;  // for numbers: a value
  Token(char ch) // make a Token from a char
      : kind(ch), value(0) {}
  Token(char ch, double val) // make a Token from a char and a double
      : kind(ch), value(val) {}
};

//------------------------------------------------------------------------------

class Token_stream {
public:
  Token_stream();        // make a Token_stream that reads from cin
  Token get();           // get a Token (get() is defined elsewhere)
  void putback(Token t); // put a Token back
private:
  bool full;    // is there a Token in the buffer?
  Token buffer; // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    : full(false), buffer(0) // no Token in buffer
{}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's
// buffer:
void Token_stream::putback(Token t) {
  if (full)
    error("putback() into a full buffer");
  buffer = t;  // copy t to buffer
  full = true; // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() {
  if (full) { // do we already have a Token ready?
    // remove token from buffer
    full = false;
    return buffer;
  }

  char ch;
  cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

  switch (ch) {
  case '=': // for "print"
  case 'x': // for "quit"
  case '(':
  case ')':
  case '{':
  case '}':
  case '+':
  case '-':
  case '*':
  case '/':
  case '!':
    return Token(ch); // let each character represent itself
  case '.':
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9': {
    cin.putback(ch); // put digit back into the input stream
    double val;
    cin >> val;             // read a floating-point number
    return Token('8', val); // let '8' represent "a number"
  }
  default:
    error("Bad token");
    return Token{'?'}; // never reached; just for compiler
  }
}

//------------------------------------------------------------------------------

Token_stream ts; // provides get() and putback()

//------------------------------------------------------------------------------

double expression(); // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers, parentheses and curly braces
double primary() {
  double d = 0;
  Token t = ts.get();
  switch (t.kind) {
  case '{': // handle '{' expression '}'
  {
    d = expression();
    t = ts.get();
    if (t.kind != '}')
      error("'}' expected");
    break;
  }
  case '(': // handle '(' expression ')'
  {
    d = expression();
    t = ts.get();
    if (t.kind != ')')
      error("')' expected");
    break;
  }
  case '8':      // we use '8' to represent a number
    d = t.value; // return the number's value
    break;
  case '-': // unary minus
    return -primary();
  case '+': // unary plus (no-op)
    return primary();
  default:
    error("primary expected");
    return 0; // never reached; just for compiler
  }
  t = ts.get();
  while (t.kind == '!') {
    if (d < 0)
      error("factorial is undefined for negative numbers");
    d = tgamma(d + 1);
    t = ts.get();
  }
  ts.putback(t);
  return d;
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term() {
  double left = primary();
  Token t = ts.get(); // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '*':
      left *= primary();
      t = ts.get();
      break;
    case '/': {
      double d = primary();
      if (d == 0)
        error("divide by zero");
      left /= d;
      t = ts.get();
      break;
    }
    default:
      ts.putback(t); // put t back into the token stream
      return left;
    }
  }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression() {
  double left = term(); // read and evaluate a Term
  Token t = ts.get();   // get the next token from token stream

  while (true) {
    switch (t.kind) {
    case '+':
      left += term(); // evaluate Term and add
      t = ts.get();
      break;
    case '-':
      left -= term(); // evaluate Term and subtract
      t = ts.get();
      break;
    default:
      ts.putback(t); // put t back into the token stream
      return left;   // finally: no more + or -: return the answer
    }
  }
}

//------------------------------------------------------------------------------

int main() {

  cout << "Welcome to our simple calculator.\nPlease enter expressions using "
          "floating−point numbers.\nOperators available: "
          "'(' ')' '{' '}' '+' '-' '*' '/'\nEnter = to print and x to quit.\n";

  try {
    while (cin) {
      double val = expression();
      Token t = ts.get();

      if (t.kind == 'x')
        break;           // 'q' for quit
      if (t.kind == '=') // ';' for "print now"
        cout << "=" << val << '\n';
      else
        ts.putback(t);
    }
    keep_window_open();
  } catch (exception &e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
  } catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
  }
}

// Add a factorial operator: use a suffix ! operator to represent “factorial.”
// For example, the expression 7! means 7 * 6 * 5 * 4 * 3 * 2 * 1. Make ! bind
// tighter than * and /; that is, 7*8! means 7*(8!) rather than (7*8)!. Begin by
// modifying the grammar to account for a higher-level operator. To agree
// with the standard mathematical definition of factorial, let 0! evaluate to
// 1. Hint: The calculator functions deal with doubles, but factorial is
// defined only for ints, so just for x!, assign the x to an int and calculate
// the factorial of that int.
