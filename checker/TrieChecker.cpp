//
// Created by admin on 17.03.2020.
//

#include "TrieChecker.h"

TrieChecker::TrieChecker() {

}

TrieChecker::~TrieChecker() {

}

void TrieChecker::add(std::string word)
{
    dictionary.add(word);

}

bool TrieChecker::check(std::string word)
{
    fixWord(word);
    if (word.empty())
        return true;
    return dictionary.check(word);
}
