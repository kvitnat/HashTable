#include <iostream>
#include <vector>

#ifndef HASHTABLE_TRIE_H
#define HASHTABLE_TRIE_H

struct Node
{
    static const int N = 27;
    Node** letters;
    bool word = false;
    char letter;
    Node()
    {
        letters = new Node*[N];

        for(int i = 0; i < N; ++i)
            letters[i] = nullptr;
    }
    Node(char c)
    {
        letters = new Node*[N];

        for(int i = 0; i < N; ++i)
            letters[i] = nullptr;
        letter = c;
    }
};

class Trie {
    Node* root;
public:
    Trie();
    void add(std::string &w);
    bool check(std::string &w);
};


#endif //HASHTABLE_TRIE_H
