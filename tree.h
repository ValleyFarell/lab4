#include "ArraySequence.h"
#include <iostream>

using namespace std;

template<class T>
class Tree {
    private:
        struct NodeT {
            NodeT *left;
            NodeT *right;
            T key;
            NodeT(T item) : left(nullptr), right(nullptr), key(item) {}
        };
        void print(const string& prefix, const NodeT* node, bool isLeft)
        {
            if( node != nullptr )
            {
                cout << prefix;
                cout << (isLeft ? "├──" : "└──" );
                cout << node->key << std::endl;
                print( prefix + (isLeft ? "│   " : "    "), node->left, true);
                print( prefix + (isLeft ? "│   " : "    "), node->right, false);
            }
        }
        NodeT *root;
    public:
        Tree() {
            root = nullptr;
        }
        Tree(ArraySequence<T> array) {
            root = nullptr;
            for (size_t i = 0; i != array.GetLength(); ++i) {
                this->Insert(array[i]);
            }
        }
        ~Tree() {
            removeBranch(root);
        }
        void printTree() {
            this->print("", root, false);
        }
        void Insert(T x) {
            if (root == nullptr) {
                NodeT *newNode = new NodeT(x);
                root = newNode;
                return;
            }
            NodeT** cur = &root;
            while (*cur != nullptr) {
                NodeT& node = **cur;
                if (x < node.key) {
                    cur = &node.left;
                } else if (x > node.key) {
                    cur = &node.right;
                } else {
                    return;
                }
            }
            *cur = new NodeT(x);
        }
        NodeT * deleteNode(NodeT * node) {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
            }
        }
        NodeT ** findNode(T x) {
            NodeT** cur = &root;
            while (*cur != nullptr) {
                NodeT& node = **cur;
                if (x == node.key) return cur;
                if (x < node.key) {
                    cur = &node.left;
                } else if (x > node.key) {
                    cur = &node.right;
                }
            }
            return nullptr;
        }
        void removeBranch(NodeT *node) {
            if (node != nullptr) {
                removeBranch(node->left);
                removeBranch(node->right);
                delete node;
                node->left = nullptr;
                node->right = nullptr;
            }
        }
        void removeBranchByValue(T value) {
            NodeT **currNode = findNode(value);
            this->removeBranch(*currNode);
            *currNode = nullptr;
        }
};
