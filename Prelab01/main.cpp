#include <iostream>
#include "xToN.h"

using namespace std;

int main()
{
    int x, y, z;
    cout << "Enter the base: ";
    cin >> x;
    cout << "Enter the exponent: ";
    cin >> y;
    z = xton(x, y);
    cout << x << " ^ " << y << " = " << z << endl;
    return 0;
}