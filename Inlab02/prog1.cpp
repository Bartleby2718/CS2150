#include <iostream>
using namespace std;

void my_subroutine() {
    cout << "Hello world" << endl;
}

int main() {
    int x = 4;
    int *p = NULL;
    my_subroutine();
    *p = 3;  // TODO: p = &int(3); and delete p later
    cout << x << ", " << *p << endl;
    return 0;
}
