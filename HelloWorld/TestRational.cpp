//
// Created by bartl on 05/08/2019.
//

#include <iostream>
#include "Rational.h"

using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    Rational x, y, z;
    x = Rational(1, 2);
    y = Rational(1, 3);
    z = x.plus(y);
    z.print();

    // pointer & swap
    int a = 1;
    int b = 2;
    int *p = &a;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "a: " << a << ", b: " << b << endl;
    swap(&a, &b);
    cout << "a: " << a << ", b: " << b << endl;

    int n;
    cout << "Please enter an integer value: ";
    cin >> n;
    int *ages = new int[n];
    for (int i = 0; i < n; ++i)
    {
        ages[i] = i + 1;
    }
    delete[] ages;

    int *intPointer2 = new int(5);  // pointer that points to an int of value 5
    delete intPointer2;

    string inputLine;
    cout << "Do you want to say anything to the audience? ";
    getline(cin, inputLine);
    cout << "You wanted to say \"" << inputLine <<"\"!";

    return 0;
}