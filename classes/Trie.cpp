//
// Created by admin on 17.03.2020.
//

#include "Trie.h"

Trie::Trie() {
    root = new Node();
}

void Trie::add(std::string &w)
{
    Node* current = root;

    int index;
    for(int i = 0; i < w.length(); ++i)
    {
        if(w[i] == '\'')
            index = 26;
        else
            index = w[i] - 'a';

        if (current->letters[index] == nullptr)
            current->letters[index] = new Node(w[i]);

        current = current->letters[index];
    }
    current->word = true;
}

bool Trie::check(std::string &w) {
    Node* current = root;
    int index;
    for(char i : w)
    {
        if(i == '\'')
            index = 26;
        else
            index = i - 'a';

        if (current->letters[index] == nullptr)
            return false;

        current = current->letters[index];
    }
    return current->word;
}
