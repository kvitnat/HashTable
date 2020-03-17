//
// Created by admin on 12.03.2020.
//

#include "Checker.h"
void fixWord(std::string& w)
{
    std::string fixedWord;
    for(int i = 0; i < w.length(); ++i)
    {
        if((w[i] >= 'a' && w[i] <= 'z') ||
           (w[i] == '\'' && i != 0 && i != w.length() - 1))
            fixedWord += w[i];
        if(w[i] >= 'A' && w[i] <= 'Z')
            fixedWord += (w[i] + ('a' - 'A'));
    }
    w.assign(fixedWord);
}