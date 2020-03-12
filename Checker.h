//
// Created by admin on 12.03.2020.
//
#include <iostream>

#ifndef HASHTABLE_CHECKER_H
#define HASHTABLE_CHECKER_H


class Checker {
public:
    virtual ~Checker()= default;
    virtual void add(std::string) = 0;
    virtual bool check(std::string) = 0;

};


#endif //HASHTABLE_CHECKER_H
