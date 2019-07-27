/** copied from huffmanNode.cpp in Prelab10 and modified */
#include <iostream>
#include <string>
#include "huffmanNode.h"

using namespace std;

HuffmanNode::HuffmanNode() :
        c('\n'), frequency(0), left(nullptr), right(nullptr)
{
}

void HuffmanNode::traverseFromLeftToRightAndPrint(const string& prefix)
{
    if (left == nullptr && right == nullptr)
    {
        cout << c << ' ' << prefix << endl;
    }
    else if (left != nullptr && right != nullptr)
    {
        left->traverseFromLeftToRightAndPrint(prefix + '0');
        right->traverseFromLeftToRightAndPrint(prefix + '1');
    }
    else
    {
        throw "Something is wrong.";
    }
}
