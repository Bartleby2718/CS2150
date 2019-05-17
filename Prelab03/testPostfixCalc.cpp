#include <iostream>
#include "postfixCalculator.h"

using namespace std;

int main()
{
    PostfixCalculator p;
    p.pushNum(1);
    p.pushNum(2);
    p.pushNum(3);
    p.pushNum(4);
    p.pushNum(5);
    p.add();
    p.add();
    p.add();
    p.add();
    cout << "expected 15, got " << p.getTopValue() << endl;

    PostfixCalculator p2;
    p2.pushNum(3);
    p2.pushNum(6);
    p2.add();
    p2.pushNum(8);
    p2.pushNum(4);
    p2.divide();
    p2.subtract();
    cout << "expected 7, got " << p2.getTopValue() << endl;

    PostfixCalculator p3;
    p3.pushNum(3);
    p3.negate();
    p3.pushNum(15);
    p3.add();
    p3.pushNum(4);
    p3.multiply();
    p3.pushNum(6);
    p3.subtract();
    p3.pushNum(2);
    p3.divide();
    cout << "expected 21, got " << p3.getTopValue() << endl;
    return 0;
}
