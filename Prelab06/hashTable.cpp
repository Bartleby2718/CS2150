//
// Created by bartl on 06/22/2019.
//
#include <algorithm>
#include <fstream>
#include "hashTable.hpp"

bool checkPrime(unsigned int p)
{
    if (p <= 1)
    { // 0 and 1 are not primes; the are both special cases
        return false;
    }
    if (p == 2)
    { // 2 is prime
        return true;
    }
    if (p % 2 == 0)
    { // even numbers other than 2 are not prime
        return false;
    }
    for (int i = 3; i * i <= p; i += 2)
    { // only go up to the sqrt of p
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}

int getNextPrime(unsigned int n)
{
    while (!checkPrime(++n))
    {
    }
    return n; // all your primes are belong to us
}


double HashTable::getLoadFactor() const
{
    return numEntries / (double) tableSize;
}

HashTable::HashTable(char *dictionaryFileName)
{
    tableSize = getNextPrime(4);
    buckets.resize(tableSize);
    numEntries = 0;
    loadFactorThreshold = 0.75;
    ifstream dictionary(dictionaryFileName);
    string word;
    while (dictionary >> word)
    {
        if (getLoadFactor() > loadFactorThreshold)
        {
            rehash();
        }
        insert(word);
    }
}

bool HashTable::contains(const string &word) const
{
    unsigned int index = hash(word);
    const list<string> &bucket = buckets.at(index);
    return find(bucket.begin(), bucket.end(), word) != bucket.end();
}

unsigned int HashTable::hash(const string &word) const
{
    unsigned long sum = 0, power = 1;
    for (char c:word)
    {
        sum += (c * power);
        power *= 37;
    }
    return sum % tableSize;
}

void HashTable::rehash()
{
    vector<list<string>> oldBuckets = move(buckets);
    tableSize = getNextPrime(2 * tableSize);
    vector<list<string>> newBuckets(tableSize);
    buckets = move(newBuckets);
    numEntries = 0;
    for (const list<string> &bucket:oldBuckets)
    {
        for (const string &word:bucket)
        {
            insert(word);
        }
    }
}

void HashTable::insert(const string &word)
{
    unsigned int index = hash(word);
    list<string> &bucket = buckets.at(index);
    bucket.push_back(word);
    ++numEntries;
}
