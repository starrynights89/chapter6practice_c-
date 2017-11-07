#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter expression (we can handle +,-,*, and /)\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";
    double expression()
    {
        double left = term();         //read and evalute a Term
        Token t = get_token();        //get the next token
    }
}