
#include "Checker.h"
#include <unordered_set>

#ifndef HASHTABLE_HASHCHECKER_H
#define HASHTABLE_HASHCHECKER_H


class HashChecker : public Checker
{
    std::unordered_set<std::string> dictionary;
public:
    HashChecker();
    ~HashChecker() override;
    void add(std::string word) override;
    bool check(std::string word) override;
    //void create(int, int, std::vector<std::string> &) override;
};


#endif //HASHTABLE_HASHCHECKER_H
