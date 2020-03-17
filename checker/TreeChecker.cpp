//
// Created by admin on 15.03.2020.
//

#include "TreeChecker.h"

TreeChecker::TreeChecker() = default;
TreeChecker::~TreeChecker() {
}

void TreeChecker::add(std::string word)
{
    if(!word.empty())
        dictionary.add(word);
}

bool TreeChecker::check(std::string word)
{
    fixWord(word);
    if(word.empty())
        return true;
    return dictionary.check(word);
}

void TreeChecker::create(int n1, int n2, std::vector<std::string> & vect)
{
    int i = (n1 + n2)/2;
    dictionary.add(vect[i]);
    if(n1 <= n2)
    {
        create(i + 1, n2, vect);
        create(n1, i - 1, vect);
    }
}