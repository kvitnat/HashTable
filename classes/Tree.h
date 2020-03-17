#include <iostream>


template <class T>
class Tree
{
private:

    struct Node
    {
        Node* left;
        Node* right;
        T value;
        explicit Node():left(nullptr), right(nullptr)
        {}
    };
    Node * root;
public:
    Tree():root(nullptr) {}

    ~Tree()
    {
        empty(root);
    }
    void add(T v)
    {
        if(root == nullptr)
        {
            root = new Node();
            root->value = v;
            return;
        }

        Node* prevNode = root, * curNode;
        while(prevNode != nullptr)
        {
            if (v < prevNode->value)
            {
                if (prevNode->left == nullptr) {
                    prevNode->left = new Node();
                    prevNode->left->value = v;
                    return;
                } else
                    prevNode = prevNode->left;
            }
            else {

                if (prevNode->right == nullptr) {
                    prevNode->right = new Node();
                    prevNode->right->value = v;
                    return;
                }
                else
                    prevNode = prevNode->right;
            }
        }
    }

    void printTree()
    {
        printSubTree(root);
    }

    void printSubTree(Node* node)
    {
        if(node->left != nullptr)
            printSubTree(node->left);
        std::cout << node->value << ' ';
        if(node->right != nullptr)
            printSubTree(node->right);
    }

    void empty(Node* node)
    {
        if (node != nullptr)
        {
            empty(node->left);
            empty(node->right);
            delete node;
        }
    }

    bool check(T x)
    {
        return subcheck(root, x);
    }

    bool subcheck(Node* node, T x)
    {
        if(node == nullptr)
            return false;
        if (x == node->value)
            return true;
        if (x < node->value)
            return subcheck(node->left, x);
        else
            return subcheck(node->right, x);
    }
};
