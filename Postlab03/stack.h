//
// Created by bartl on 05/17/2019.
//

#ifndef POSTLAB03_STACK_H
#define POSTLAB03_STACK_H

#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;

// Most of the following code is from https://www.tutorialspoint.com/cplusplus/cpp_templates.htm
template<class T>
class stack
{
private:
    T *elements;
    unsigned capacity;
    unsigned numElements;

public:
    explicit stack(unsigned size);

    stack();

    ~stack();

    void push(T const &element);

    void pop();

    T top() const;

    bool empty() const;
};


template<class T>
stack<T>::stack(unsigned size)
{
    if (size == 0)
    {
        capacity = 2;
    }
    else
    {
        unsigned unsignedMax = numeric_limits<unsigned>::max();
        capacity = min(size, unsignedMax);
    }
    elements = new T(capacity);
    numElements = 0;
}

template<class T>
stack<T>::stack()
{
    capacity = 4;
    elements = new T(capacity);
    numElements = 0;
}

template<class T>
stack<T>::~stack()
{
    delete elements;
    elements = NULL;
}

template<class T>
void stack<T>::push(T const &element)
{
    if (numElements == capacity)
    {
        unsigned unsignedMax = numeric_limits<unsigned int>::max();
        unsigned newCapacity = min(capacity * 2, unsignedMax);
        T *temp = new T(newCapacity);
        copy(elements, elements + capacity, temp);
        delete elements;
        elements = temp;
        capacity = newCapacity;
    }
    elements[numElements++] = element;
}

template<class T>
void stack<T>::pop()
{
    // assumes numElements > 0
    --numElements;
}

template<class T>
T stack<T>::top() const
{
    // assumes numElements > 0
    return elements[numElements - 1];
}

template<class T>
bool stack<T>::empty() const
{
    return numElements == 0;
}

#endif //POSTLAB03_STACK_H
