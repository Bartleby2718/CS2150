//
// Created by bartl on 05/16/2019.
//

#ifndef PRELAB03_POSTFIXCALCULATOR_H
#define PRELAB03_POSTFIXCALCULATOR_H

#include <stack>

using namespace std;

class PostfixCalculator
{
public:
    PostfixCalculator();

    void pushNum(int e);

    int getTopValue() const;

    void pop();

    bool empty() const;

    void add();

    void subtract();  // non-commutative operator

    void multiply();

    void divide();  // non-commutative operator

    void negate();  // unary operator
private :
    stack<int> s;
};

#endif //PRELAB03_POSTFIXCALCULATOR_H
