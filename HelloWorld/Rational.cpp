//
// Created by bartl on 05/08/2019.
//

#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational() : numerator(0), denominator(1)
{
}  // default constructor: initialize to 0/1

Rational::Rational(int numerator, int denominator)
{
    if (denominator == 0)
    {
        cout << "Denominator is zero" << endl;
    }
    int g = gcd(numerator, denominator);
    this->numerator = numerator / g;
    this->denominator = denominator / g;
}

void Rational::print() const
{
    if (denominator == 1)
    {
        cout << numerator << "" << endl;
    }
    else
    {
        cout << numerator << "/" << denominator << endl;
    }
}

Rational Rational::times(Rational b) const
{
    return Rational(numerator * b.numerator, denominator * b.denominator);
}

Rational Rational::plus(Rational b) const
{
    return Rational(numerator * b.denominator + denominator * b.numerator, denominator * b.denominator);
}

Rational Rational::reciprocal() const
{
    return Rational(denominator, numerator);
}

Rational Rational::divides(Rational b) const
{
    return times(b.reciprocal());
}

int Rational::gcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    else
    {
        return gcd(n, m % n);
    }
}
