#include "std_lib_facilities.h"

double expression()
{
    double left = expression();  //read and evaluate an Expression
    Token t = get_token();       //get the next token
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