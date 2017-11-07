#include "std_lib_facilities.h"

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