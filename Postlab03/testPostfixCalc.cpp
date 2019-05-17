#include <iostream>
#include "postfixCalculator.h"

using namespace std;

int main()
{
    PostfixCalculator p;
    string token;
    while (cin >> token)
    {
        // assumes valid input
        if (token == "+")
        {
            p.add();
        }
        else if (token == "-")
        {
            p.subtract();
        }
        else if (token == "*")
        {
            p.multiply();
        }
        else if (token == "/")
        {
            p.divide();
        }
        else if (token == "~")
        {
            p.negate();
        }
        else
        {
            int i = stoi(token);
            p.pushNum(i);
        }
    }
    cout << "result: " << p.getTopValue() << endl;
    return 0;
}
