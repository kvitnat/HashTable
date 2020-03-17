
#include "HashTable.h"


HashTable::HashTable() {
    heads = new Node* [N];
    for(int i = 0; i < N; ++i)
        heads[i] = nullptr;
}

void HashTable::add(const std::string &value)
{
    unsigned int a;
    try {
        a = hash(value);
    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << '\n';
    }
    if(heads[a] == nullptr) {
        heads[a] = new Node(value);
        return;
    }

    Node* newNode = new Node(value);
    newNode->next = heads[a];
    heads[a] = newNode;
    /*
    Node* current = heads[a];
    while(true)
    {
        if(current->next != nullptr)
            current = current->next;
        else
        {
            current->next = new Node(value);
            return;
        }
    }
    */
}

bool HashTable::check(const std::string &value)
{
    unsigned int a = hash(value);

    if (heads[a] == nullptr)
        return false;

    Node* current = heads[a];
    while(current != nullptr)
    {
        if (current->word == value)
            return true;
        else
            current = current->next;
    }
    return false;
}

unsigned int HashTable::hash(const std::string &value)
{
    unsigned int hash = 0;
    int i = 0;
    int p = 1;
    while(i < 4 && i < value.length())
    {
        if (value[i] == '\'')
            hash+=27 * p;
        else
            hash+=(value[i] - 'a' + 1) * p;
        i++;
        p *= 27;
    }



    if (hash > N - 1)
        throw std::out_of_range("hash");
    return hash;
}

int HashTable::getMaxCollisions() const
{
    int collisions = 0;
    int temp = 0;
    for(int i = 0; i < N; i++)
    {
        Node* current = heads[i];
        while(current != nullptr)
        {
            temp++;
            current = current->next;
        }
        if(temp > collisions)
            collisions = temp;
        temp = 0;

    }
    return collisions;
}
