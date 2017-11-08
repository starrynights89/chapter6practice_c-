#include "std_lib_facilities.h"

class Token
{
public:
    char kind; //what kind of token
    double value; //for numbers: a value
};

Token get_token(); //function to read a token from cin

vector<Token>tok; //we'll put the tokens here

int main()
try
{
    while (cin)
    {
        Token t = get_token();
        tok.push_back(t);
    }
    for (int i = 0; i<tok.size(); i++)
    {
        if (tok[i].kind=='*')
        {
            double d = tok[i-1].value*tok[i+1].value;
        }
    }    
    keep_window_open();
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

double expression()
{
    double left = term(); //read and evaluate a Term
    Token t = get_token();      //get the next token
    while (t.kind == '+' || t.kind == '-') //look for a + or a -
    {
        if (t.kind == '+')
        {
            left += term(); //evaluate Term and add
        }
        else
        {
            left -= term(); //evalutate Term and subtract
        }
        t = get_token();
    }
    return left; //finally: no more + or -; return the answer
}