//
// Created by bartl on 05/16/2019.
//

#include <cstdlib>
#include "postfixCalculator.h"

PostfixCalculator::PostfixCalculator() = default;

void PostfixCalculator::pushNum(int e)
{
    // no maximum capacity
    s.push(e);
}

int PostfixCalculator::getTopValue() const
{
    if (empty())
    {
        exit(-1);
    }
    return s.top();
}

void PostfixCalculator::pop()
{
    if (empty())
    {
        exit(-1);
    }
    s.pop();
}

bool PostfixCalculator::empty() const
{
    return s.empty();
}

void PostfixCalculator::add()
{
    int first = getTopValue();
    pop();
    int second = getTopValue();
    pop();
    int sum = first + second;
    pushNum(sum);
}

void PostfixCalculator::subtract()
{
    int first = getTopValue();
    pop();
    int second = getTopValue();
    pop();
    int difference = second - first;
    pushNum(difference);
}

void PostfixCalculator::multiply()
{
    int first = getTopValue();
    pop();
    int second = getTopValue();
    pop();
    int product = first * second;
    pushNum(product);
}

void PostfixCalculator::divide()
{
    int first = getTopValue();
    pop();
    int second = getTopValue();
    pop();
    int quotient = second / first;
    pushNum(quotient);
}

void PostfixCalculator::negate()
{
    int value = getTopValue();
    pop();
    value = -value;
    pushNum(value);
}
