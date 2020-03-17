//
// Created by admin on 12.03.2020.
//
#include <iostream>
#include <vector>

#ifndef HASHTABLE_CHECKER_H
#define HASHTABLE_CHECKER_H


class Checker {
public:
    virtual ~Checker()= default;
    virtual void add(std::string) = 0;
    virtual bool check(std::string) = 0;
    virtual void create(int, int, std::vector<std::string> &dictionaryVector)
    {
        for(const std::string w : dictionaryVector)
            this->add(w);
    }

};

void fixWord(std::string& w);

#endif //HASHTABLE_CHECKER_H
