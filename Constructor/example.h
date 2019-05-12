//
// Created by bartl on 05/12/2019.
//

#ifndef CONSTRUCTOR_EXAMPLE_H
#define CONSTRUCTOR_EXAMPLE_H

#include <iostream>

using namespace std;

class example
{
public:
    example();  // default constructor
    example(int id);  // parameterized constructor
    example(const example &another);

    example &operator=(const example &another);

    int getValue() const;

private:
    int value;
};

void print(const example &e);

#endif //CONSconst TRUCTOR&_EXAMPLE_H
