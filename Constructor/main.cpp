#include <iostream>
#include "example.h"

int main()
{
    cout << "demo 1: explicit/implicit/copy constructor & assignment" << endl;
    example e1(1);  // explicit
    example e2 = example(2);  // explicit (copy elision)
    example e3(example(3));  // explicit (copy elision)
    example e4(e3);  // copy
    example e5 = e2;  // copy
    example e6;    // implicit
    e6 = e1;  // assignment

    cout << endl << "demo 2: why explicit keyword is recommended" << endl;
    print(e1);
    print(7);
    return 0;
}