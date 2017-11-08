#include "std_lib_facilities.h"

class Token
{
public:
    char kind; //what kind of token
    double value; //for numbers: a value
};

Token get_token()
{
    return Token(); //function to read a token from cinS
} 

vector<Token>tok; //we'll put the tokens here

int main()
try
{
    while (cin)
    {
        Token t = get_token();
        tok.push_back(t);
    }
    for (int i = 0; i < tok.size(); i++)
    {
        if (tok[i].kind=='*') //we found a multiply!
        {
            double d = tok[i-1].value*tok[i+1].value;
        }
    }    
    keep_window_open();
    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...)
{
    cerr << "exception \n";
    keep_window_open();
    return 2; 
}

double primary()
{
	Token t = get_token();
	switch (t.kind)
	{
	case'(': //handle '('expression')'
	{
		double d = expression();
		t = get_token();
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

double term()
{
	double left = primary(); //read and evaluate a Term
	Token t = get_token();      //get the next token
	while (true)
	{
		switch (t.kind)
		{
		case '*':
			left *= primary();
			t = get_token();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = get_token();
			break;
		}
		default:
			return left;
		}
	}
}

double expression()
{
	double left = term(); //read and evaluate a Term
	Token t = get_token(); //get the next token
	while (true)
	{
		switch (t.kind)
		{
		case '+':
			left += term(); //evaluate a Term and add
			t = get_token();
			break;
		case '-':
			left -= term(); //evaluate a Term and subtract
			t = get_token();
			break;
		default:
			return left; //finally: no more + or -; return the answer
		}
	}
}
