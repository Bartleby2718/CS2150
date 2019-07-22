/** code taken from fileio.cpp in https://github.com/aaronbloomfield/pdr
 *  and modified */
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == nullptr)
    {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    // 1. Read the source file and determine the frequencies of the characters in the file.
    char g;
    map<char, unsigned> dictionary;
    while ((g = fgetc(fp)) != EOF)
    {
        if (g == '\t' || g == '\n')
        {
            continue;
        }
        dictionary[g]++;
    }

    // 2. Store the character frequencies in a heap (priority queue).
    Heap heap;
    for (auto& pair:dictionary)
    {
        auto node = new HuffmanNode(pair.first, pair.second);
        heap.insert(node);
    }

    // 3. Build a tree of prefix codes (a Huffman code) that determines the unique bit codes for each character.
    while (heap.size() > 1)
    {
        HuffmanNode* one = heap.deleteMin();
        HuffmanNode* another = heap.deleteMin();
        auto* combined = new HuffmanNode(one, another);
        heap.insert(combined);
    }
    map<char, string> prefixCodeTable;
    HuffmanNode* tree = heap.findMin();
    tree->addToTable(prefixCodeTable, "");

    // 4. Write the prefix codes to the standard output.
    for (auto& pair:prefixCodeTable)
    {
        cout << ((pair.first == ' ') ? "space" : string(1, pair.first))
             << ": " << pair.second << endl;
    }
    cout << "----------------------------------------" << endl;

    // 5. Re-read the source file and for each character read, write its prefix code to the output.
    rewind(fp);
    unsigned numSymbolsEncoded = 0;
    unsigned numDistinctSymbolsUsed = prefixCodeTable.size();
    unsigned numBitsCompressedFile = 0;
    while ((g = fgetc(fp)) != EOF)
    {
        if (g == '\t' || g == '\n')
        {
            continue;
        }
        ++numSymbolsEncoded;
        string code = prefixCodeTable[g];
        cout << code << ' ';
        numBitsCompressedFile += code.size();
    }
    unsigned numBitsOriginalFile = 8 * numSymbolsEncoded;
    double compressionRatio = numBitsOriginalFile / (double) numBitsCompressedFile;
    double costPerCharacter = numBitsCompressedFile / (double) numSymbolsEncoded;
    fclose(fp);
    cout << endl << "----------------------------------------" << endl
         << "There are a total of " << numSymbolsEncoded << " symbols that are encoded." << endl
         << "There are " << numDistinctSymbolsUsed << " distinct symbols used." << endl
         << "There were " << numBitsOriginalFile << " bits in the original file." << endl
         << "There were " << numBitsCompressedFile << " bits in the compressed file." << endl
         << "This gives a compression ratio of " << compressionRatio << "." << endl
         << "The cost of the Huffman tree is " << costPerCharacter << " bits per character." << endl;
}
