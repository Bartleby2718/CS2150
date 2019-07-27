/** taken from inlab-skeleton.cpp */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "huffmanNode.h"

using namespace std;

int main(int argc, char** argv)
{
    // Guard statement 1: number of parameters
    if (argc != 2)
    {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    ifstream file(argv[1], ifstream::binary);
    // Guard statement 2: existence of the file
    if (!file.is_open())
    {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // Create a Huffman tree, reading the file until the separator
    auto root = new HuffmanNode();
    while (true)
    {
        string character, prefix;
        file >> character;
        if ((character[0] == '-') && (character.length() > 1))
        {
            break;
        }
        if (character == "space")
        {
            character = " ";
        }
        file >> prefix;
        HuffmanNode* node = root;
        for (char c : prefix)
        {
            if (c == '0')
            {
                if (node->left == nullptr)
                {
                    node->left = new HuffmanNode();
                }
                node = node->left;
            }
            else if (c == '1')
            {
                if (node->right == nullptr)
                {
                    node->right = new HuffmanNode();
                }
                node = node->right;
            }
        }
        char c = character.at(0);
        node->c = c;
    }

    // Traverse the Huffman tree
    // root->traverseFromLeftToRightAndPrint("");

    // Continue reading the second part of the file
    stringstream sstm;
    while (true)
    {
        string bits; // encoded4a.txt requires some modifications (e.g. string->char)
        file >> bits;
        if (bits[0] == '-')
        {
            break;
        }
        HuffmanNode* node = root;
        for (char c:bits)
        {
            node = (c == '0') ? (node->left) : (node->right);
        }
        char decodedChar = node->c;
        sstm << decodedChar;
    }
    string decoded = sstm.str();
    // cout << "After decompression: ";
    cout << decoded << endl;
    file.close();
}
