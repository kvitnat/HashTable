
#include "MyHashChecker.h"

MyHashChecker::MyHashChecker() = default;

MyHashChecker::~MyHashChecker() = default;

void MyHashChecker::add(std::string word)
{
    dictionary.add(word);
}

bool MyHashChecker::check(std::string word)
{
    fixWord(word);
    if (word.empty())
        return true;
    return dictionary.check(word);
}

int MyHashChecker::collisions()
{
    return dictionary.getMaxCollisions();
}

