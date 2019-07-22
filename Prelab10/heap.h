/** code taken from binary_heap.h in https://github.com/aaronbloomfield/pdr
 *  and modified */
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffmanNode.h"

using namespace std;

class Heap
{
public:
    Heap();

    ~Heap();

    void insert(HuffmanNode* x);

    HuffmanNode* findMin() const;

    HuffmanNode* deleteMin();

    unsigned int size() const;

    void print() const;

private:
    vector<HuffmanNode*> heap;
    unsigned int heap_size;

    void percolateUp(int hole);

    void percolateDown(int hole);
};

#endif
