#include <iostream>
#include <string>
#include "huffmanNode.h"

using namespace std;

HuffmanNode::HuffmanNode() :
        c('\n'), frequency(0), left(nullptr), right(nullptr)
{
}

HuffmanNode::HuffmanNode(char c, unsigned frequency) :
        c(c), frequency(frequency), left(nullptr), right(nullptr)
{
}


HuffmanNode::HuffmanNode(HuffmanNode* left, HuffmanNode* right) :
        c('\n'), left(left), right(right)
{
    frequency = left->frequency + right->frequency;
}

string HuffmanNode::toString() const
{
    return string(1, c) + "(" + to_string(frequency) + ")";
}

void HuffmanNode::addToTable(map<char, string>& table, const string& prefix)
{
    if (left == nullptr && right == nullptr)
    {
        table[c] = prefix;
    }
    else if (left != nullptr && right != nullptr)
    {
        left->addToTable(table, prefix + '0');
        right->addToTable(table, prefix + '1');
    }
    else
    {
        throw "The tree is not full.";
    }
}

bool operator<(const HuffmanNode& lhs, const HuffmanNode& rhs)
{
    return lhs.frequency < rhs.frequency;
}

bool operator>(const HuffmanNode& lhs, const HuffmanNode& rhs)
{
    return operator<(rhs, lhs);
}

ostream& operator<<(ostream& os, const HuffmanNode& node)
{
    os << node.toString();
    return os;
}
