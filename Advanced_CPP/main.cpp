#include <iostream>

using namespace std;

/** Dynamic Memory Allocation */
// // Example 1: assigning the address of a local variable
// void someFunc(int * somePointer) {
//     int someNode(3);
//     somePointer = &someNode;
// }
//
// int main() {
//     int * firstPointer;
//     // call someFunc
//     someFunc(firstPointer);
//     cout << *firstPointer << endl;
//     return 0;
// }

// // Example 2: no problem
// void someFunc() {
//     double *aliasPointer;
//     aliasPointer = new double(6.27);
//     cout << *aliasPointer << endl;
// }
//
// int main() {
//     double *somePointer;
//     double someVal(3.14);
//     somePointer = &someVal;
//     someFunc();
//     cout << *somePointer << endl;
//     return 0;
// }

// // Example 3: assigning the address of a local variable
// int main() {
//     double duration = 3.14;
//     {
//         double * somePtr;
//         {
//             somePtr = &duration;
//         }
//     }
//     cout << *somePtr << endl;
//     return 0;
// }

// // Example 4: dereferencing an uninitialized pointer
// int main() {
//     int * anotherPtr;
//     {
//         int someVal(8);
//         cout << *anotherPtr << endl;
//         anotherPtr = &someVal;
//     }
//
//     return 0;
// }

// // Example 5: assigning the address of a local variable
// void someFunc(int *somePointer) {
//     int someVal(12);
//     {
//         int anotherVal(16);
//         somePointer = &anotherVal;
//     }
// }
//
// int main() {
//     int * yetAnotherPtr;
//     someFunc(yetAnotherPtr);
//     cout << *yetAnotherPtr << endl;
//     return 0;
// }

// // Example 6: no problem
// int main() {
//     float * somePtr;
//     somePtr = new float(3.14);
//     cout << *somePtr << endl;
//     delete somePtr;
//     return 0;
// }

// // Example 7: no problem
// void someFunc() {
//     int *aliasPtr;
//     aliasPtr = new int(25);
//     cout << *aliasPtr << endl;
// }
//
// int main() {
//     int * somePtr;
//     somePtr = new int(3);
//     someFunc();
//     cout << *somePtr << endl;
//     return 0;
// }
