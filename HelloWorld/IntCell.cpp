//
// Created by bartl on 05/05/2019.
//

#include "IntCell.h"


IntCell::IntCell(int initialValue) : storedValue(initialValue)
{
}

int IntCell::getValue() const
{
    return storedValue;
}

void IntCell::setValue(int val)
{
    storedValue = val;
}

int IntCell::max(int m) const
{
    return (m > storedValue) ? m : storedValue;
}