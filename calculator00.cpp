#include "std_lib_facilities.h"

class Token
{
public:
    char kind; //what kind of token
    double value; //for numbers: a value
};

class Token_stream
{
public:
    Token_stream();
    Token get();
    void putback(Token t);
private:
    bool full;
    Token buffer;
};

Token_stream ts;

double term(); 

double expression()
{     
    double left = term();        //evaluate an expression
    Token t = ts.get();          //get the next token
    switch(t.kind)               //see which kind of token it is
    {
        case '+':
            return left + term(); //read and evalute a Term then do an add
        case '-':
            return left - term(); //read and evalute a Term then do a subtraction
        default:
            return left;          //return the value of the Expression
    }
}

int main()
try
{
    while (cin)
        cout << expression() << '\n';
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