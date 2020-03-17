#include "../classes/Trie.h"
#include "../checker/Checker.h"

#ifndef HASHTABLE_TRIECHECKER_H
#define HASHTABLE_TRIECHECKER_H


class TrieChecker : public Checker
{
    Trie dictionary;
public:
    TrieChecker();
    ~TrieChecker() override;
    void add(std::string word) override;
    bool check(std::string word) override ;
};


#endif //HASHTABLE_TRIECHECKER_H
