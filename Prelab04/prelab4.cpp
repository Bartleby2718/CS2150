#include <iostream>
#include <limits>

using namespace std;

void sizeOfTest()
{
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(bool) = " << sizeof(bool) << endl;
    cout << "sizeof(int*) = " << sizeof(int *) << endl;
    cout << "sizeof(char*) = " << sizeof(char *) << endl;
    cout << "sizeof(double*) = " << sizeof(double *) << endl;
}

void outputBinary(unsigned int x)
{
    cout << "outputBinary(" << x << ") //=>";
    char binary[32];
    for (int i = 31; i >= 0; --i, x >>= 1U)
    {
        binary[i] = x % 2 == 1 ? '1' : '0';
    }
    for (int i = 0; i < 8; ++i)
    {
        cout << " ";
        for (int j = 0; j < 4; ++j)
        {
            cout << binary[i * 4 + j];  // big Endian
        }
    }
    cout << endl;
}

void overflow()
{
    unsigned int unsignedIntMax = numeric_limits<unsigned int>::max();
    cout << unsignedIntMax << " + 1 = " << unsignedIntMax + 1 << endl;
}

int main()
{
    sizeOfTest();
    unsigned int x;
    cin >> x;
    outputBinary(x);
    overflow();
    return 0;
}
