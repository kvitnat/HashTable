//
// Created by admin on 15.03.2020.
//

#include "HashChecker.h"

HashChecker::HashChecker() = default;

HashChecker::~HashChecker() = default;

void HashChecker::add(std::string word)
{
    dictionary.insert(word);
}

bool HashChecker::check(std::string word)
{
    fixWord(word);
    if(word.empty())
        return true;
    return !(dictionary.find(word) == dictionary.end());
}


