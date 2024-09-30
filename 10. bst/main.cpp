#include "binarySearchTree.h"
#include <iostream>

int main()
{
    binarySearchTree bst;
    Node *temp;

    bst.insert(50);
    bst.insert(10);
    bst.insert(40);
    bst.insert(20);
    bst.rInsert(bst.getRoot(), 30);
    bst.deleteNode(bst.getRoot(), 50);

    bst.inorder(bst.getRoot());
    
    std::cout << '\n';

    temp = bst.search(20);
    if(temp) std::cout << "found!\n";
    else std::cout << "not found!\n";

    return 0;
}