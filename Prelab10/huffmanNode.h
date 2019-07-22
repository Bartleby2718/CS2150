#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <map>
#include <string>

using namespace std;

class HuffmanNode
{
public:
    HuffmanNode();

    HuffmanNode(char c, unsigned frequency);

    HuffmanNode(HuffmanNode* left, HuffmanNode* right);

    string toString() const;

    void addToTable(map<char, string>& table, const string& prefix);

    friend bool operator<(const HuffmanNode& lhs, const HuffmanNode& rhs);

    friend bool operator>(const HuffmanNode& lhs, const HuffmanNode& rhs);

    friend ostream& operator<<(ostream& os, const HuffmanNode& node);

private:
    char c;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;
};

#endif
