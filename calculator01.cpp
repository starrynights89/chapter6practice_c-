#include "std_lib_facilities.h"

class Token
{
public:
    char kind; //what kind of token
    double value; //for numbers: a value
	Token(char ch) //make a Token from char
		:kind(ch), value(0) {}
	Token(char ch, double val) //make a Token from a char and a double
		:kind(ch), value(val) {}
};

class Token_stream
{
public:
	Token_stream(); //make a Token_stream that reads from cin
	Token get(); //get a Token (get() is defined elswhere)
	void putback(Token t); //put a Token back 
private:
	bool full; // is there a Token in 
	Token buffer; 
};

Token get() //read a token from cin 
{
	char ch;
	cin >> ch; //note that >> skips whitespace (space, newline, tab, etc.)
	
	switch (ch)
	{
		case ';': //not yet for "print"
		case 'q': //net yet for "quit"
		case '(': case ')': case '+': case '-':  case '*': case '/':
			return Token(ch); //let each charcter represent itself
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(ch); // put digit back into the input stream 
			double val;
			cin >> val; //read a floating-point number
			return Token('8', val); //let '8' represent "a number"
		}
		default: 
			error("Bad token"); 
	}
}

vector<Token>tok; //we'll put the tokens here

Token_stream ts; //provides get() and putback()

double expression(); //read and evalute a Expression

double term(); //read and evaluate a Term

double primary() //read and evaluate a Primary 
{
	Token t = ts.get();
	switch (t.kind)
	{
	case'(': //handle '('expression')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		{
			return d;
		}
	}
	case '8': //we use '8' to represent a number
		return t.value; //return the number's value
	default:
		error("primary expected");
	}
}

int main()
try
{
	while (cin)
	{
		cout << "=" << expression() << '\n'; //version 1
	}
    keep_window_open("~0");
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    keep_window_open("~1");
    return 1;
}
catch (...)
{
    cerr << "exception \n";
    keep_window_open("~2");
    return 2; 
}

double expression()
{
	double left = term(); //read and evaluate a Term
	Token t = ts.get(); //get the next Token from the Token stream
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term(); //evaluate a Term and add
			t = ts.get();
			break;
		case '-':
			left -= term(); //evaluate a Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t); //put t back into the token stream
			return left; //finally: no more + or -; return the answer
		}
	}
}

double term()
{
	double left = primary(); //read and evaluate a Term
	Token t = ts.get();      //get the next Token from the Token stream
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t); //put t back into the Token stream
			return left;
		}
	}
}
