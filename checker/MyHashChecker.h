#include "Checker.h"
#include "HashTable.h"

#ifndef HASHTABLE_MYHASHCHECKER_H
#define HASHTABLE_MYHASHCHECKER_H


class MyHashChecker : public Checker
{
    HashTable dictionary;
public:
    MyHashChecker();
    ~MyHashChecker() override;
    void add(std::string word) override;
    bool check(std::string word) override;
    int collisions();
};


#endif //HASHTABLE_MYHASHCHECKER_H
