//
// Created by bartl on 05/05/2019.
//

#ifndef HELLOWORLD_INTCELL_H
#define HELLOWORLD_INTCELL_H

class IntCell
{
public:
    IntCell(int initialValue = 0);

    int getValue() const;

    void setValue(int val);

private:
    int storedValue;

    int max(int m) const;
};

#endif
