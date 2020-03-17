#include "Checker.h"
#include "../classes/Tree.h"

#ifndef HASHTABLE_TREECHECKER_H
#define HASHTABLE_TREECHECKER_H


class TreeChecker : public Checker
{
    Tree<std::string> dictionary;
public:
    TreeChecker();
    ~TreeChecker() override;
    void add(std::string word) override;
    bool check(std::string word) override ;
    void create(int n1, int n2, std::vector<std::string> & vect) override;
};


#endif //HASHTABLE_TREECHECKER_H
