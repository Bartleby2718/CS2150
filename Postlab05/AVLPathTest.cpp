#include "AVLTree.h"

#include <iostream>

using namespace std;

int main()
{
    AVLTree avl;
    while (cin.good())
    {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I")
        {
            avl.insert(word);
            avl.printTree();
        }
        else if (instr == "R")
        {
            avl.remove(word);
            avl.printTree();
        }
        else if (instr == "L")
        {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }
    }
    cout << "AVL numNodes: " << avl.numNodes() << endl;
}
