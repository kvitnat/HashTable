//
// Created by admin on 12.03.2020.
//

#include "VectorChecker.h"

VectorChecker::VectorChecker() = default;
VectorChecker::~VectorChecker() = default;

void VectorChecker::add(std::string word)
{
    dictionary.push_back(word);
}

bool VectorChecker::check(std::string word)
{
    fixWord(word);
    if(word.empty())
        return true;
    long N1 = 0;
    long N2 = dictionary.size() - 1;

    while(N1 <= N2)
    {
        if(word == dictionary[int((N2 + N1)/2)])
            return true;
        if(word < dictionary[int((N2 + N1)/2)])
            N2 = int((N2 + N1)/2) - 1;
        else
            N1 = int((N2 + N1)/2) + 1;
    }
    return false;
}

