#include <iostream>

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H



class HashTable {
private:
    struct Node
    {
        std::string word;
        Node* next = nullptr;
        Node(){};
        Node(std::string w):word(w), next(nullptr){};
    };
    static const int N = 551881;
    Node** heads;

public:
    HashTable();
    void add (const std::string &value);
    bool check(const std::string &value);
    unsigned int hash(const std::string &value);
    int getMaxCollisions() const;
};


#endif //HASHTABLE_HASHTABLE_H
