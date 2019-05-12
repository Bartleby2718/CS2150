//
// Created by bartl on 05/10/2019.
//

#include "xToN.h"

int xton(int base, int exponent)
{
    // a recursive function called xton() to compute x^n for non-negative integers n (x^0=1)
    if (exponent == 0)
    {
        return 1;
    }
    else
    {
        return base * xton(base, exponent - 1);
    }
}
