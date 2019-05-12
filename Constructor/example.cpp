//
// Created by bartl on 05/12/2019.
//

#include "example.h"

example::example(int id)
{
    this->value = id;
    cout << "explicit constructor called: created " << this->value << endl;
}

example::example()
{
    value = 0;
    cout << "implicit constructor called: created " << this->value << endl;
}

example::example(const example &another)
{
    this->value = another.value;
    cout << "copy constructor called: copied " << this->value << endl;
}

example &example::operator=(const example &another)
{
    cout << another.value << " assigned (originally " << this->value << ")" << endl;
    if (this != &another)
    {
        this->value = another.value;
    }
    return *this;
}

int example::getValue() const
{
    return value;
}

void print(const example &e)
{
    cout << e.getValue() << endl;
}