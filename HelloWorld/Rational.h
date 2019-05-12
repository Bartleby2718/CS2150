//
// Created by bartl on 05/08/2019.
//

#ifndef HELLOWORLD_RATIONAL_H
#define HELLOWORLD_RATIONAL_H


class Rational
{
public:
    Rational();  // default constructor
//    ~Rational(); // destructor
    Rational(int numerator, int denominator);

    void print() const;

    Rational times(Rational b) const;

    Rational plus(Rational b) const;

    Rational reciprocal() const;

    Rational divides(Rational b) const;

private:
    int numerator, denominator;

    static int gcd(int m, int n);
};


#endif //HELLOWORLD_RATIONAL_H
