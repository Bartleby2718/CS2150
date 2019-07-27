/** copied from huffmanNode.h in Prelab10 and modified */
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

using namespace std;

class HuffmanNode
{
public:
    HuffmanNode();

    void traverseFromLeftToRightAndPrint(const string& prefix);

    HuffmanNode* left;
    HuffmanNode* right;
    char c;
private:
    unsigned frequency;
};

#endif
