/** code taken from binary_heap.cpp in https://github.com/aaronbloomfield/pdr
 *  and modified */
#include <iostream>
#include "heap.h"

using namespace std;

Heap::Heap() : heap_size(0)
{
    heap.emplace_back();
}

Heap::~Heap() = default;

void Heap::insert(HuffmanNode* x)
{
    heap.push_back(x);
    percolateUp(++heap_size);
}

HuffmanNode* Heap::findMin() const
{
    if (heap_size == 0)
    {
        throw "findMin() called on empty heap";
    }
    return heap[1];
}

HuffmanNode* Heap::deleteMin()
{
    if (heap_size == 0)
    {
        throw "deleteMin() called on empty heap";
    }
    HuffmanNode* ret = heap[1];
    heap[1] = heap[heap_size--];
    heap.pop_back();
    percolateDown(1);
    return ret;
}

unsigned Heap::size() const
{
    return heap_size;
}

void Heap::print() const
{
    cout << '\t';
    for (unsigned  i = 1; i <= heap_size; i++)
    {
        cout << *heap[i] << " ";
        bool isPow2 = (((i + 1) & ~(i)) == (i + 1)) ? i + 1 : 0;
        if (isPow2)
        {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

void Heap::percolateUp(int hole)
{
    HuffmanNode* x = heap[hole];
    for (; (hole > 1) && (*x < *heap[hole / 2]); hole /= 2)
    {
        heap[hole] = heap[hole / 2];
    }
    heap[hole] = x;
}

void Heap::percolateDown(int hole)
{
    HuffmanNode* x = heap[hole];
    while (hole * 2 <= heap_size)
    {
        int child = hole * 2;
        if ((child + 1 <= heap_size) && (*heap[child + 1] < *heap[child]))
        {
            child++;
        }
        if (*x > *heap[child])
        {
            heap[hole] = heap[child];
            hole = child;
        }
        else
        {
            break;
        }
    }
    heap[hole] = x;
}
