#include<iostream>
#include"tree.h"

using namespace std;

int main() {
    int a[12] = {1, 5, 3, 8, 5, 9, 1, 123, 239, 44, 50, 88};
    ArraySequence<int> arr(a, 12);
    Tree<int> Tree(arr);
    Tree.printTree();
    Tree.removeBranchByValue(5);
    Tree.printTree();
}
