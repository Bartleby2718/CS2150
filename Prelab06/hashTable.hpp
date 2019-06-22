//
// Created by bartl on 06/22/2019.
//

#ifndef PRELAB06_HASHTABLE_HPP
#define PRELAB06_HASHTABLE_HPP

#include <list>
#include <string>
#include <vector>

using namespace std;

bool checkPrime(unsigned int p);

int getNextPrime(unsigned int n);

class HashTable
{
    int tableSize;
    int numEntries;
    double loadFactorThreshold;
    vector<list<string>> buckets;

    double getLoadFactor() const;

public:
    explicit HashTable(char *dictionaryFileName);

    bool contains(const string &word) const;

    unsigned int hash(const string &word) const;

    void rehash();

    void insert(const string &word);
};

#endif //PRELAB06_HASHTABLE_HPP
