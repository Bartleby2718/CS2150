#include <iostream>

using namespace std;

int count1s(int n)
{
    /** a recursive function that returns the number of 1's in the binary representation of n.
     *  Use the following fact: if n is even, the number of 1's in the representation of n is the same
     *  as that in n/2; if n is odd, the number of 1's is the same as that in floor(n/2) plus 1. */
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return n % 2 == 0 ? count1s(n / 2) : count1s(n / 2) + 1;
    }
}

int main(int argc, char **argv)
{
    char *argumentInCharArray = argv[1];
    string argumentInString = string(argumentInCharArray);
    int argumentInInt = stoi(argumentInString);
    cout << count1s(argumentInInt) << endl;
    return 0;
}
