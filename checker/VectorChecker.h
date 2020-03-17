#include "Checker.h"

#ifndef HASHTABLE_VECTORCHECKER_H
#define HASHTABLE_VECTORCHECKER_H


class VectorChecker : public Checker{
    std::vector<std::string> dictionary;
public:
    VectorChecker();
    ~VectorChecker() override;
    void add(std::string word) override;
    bool check(std::string word) override ;
};


#endif //HASHTABLE_VECTORCHECKER_H
