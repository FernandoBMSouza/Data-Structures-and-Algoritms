#include "binarySearchTree.h"
#include <iostream>

int main()
{
    binarySearchTree bst;
    Node *temp;

    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    bst.insert(8);
    bst.insert(30);

    bst.inorder(bst.getRoot());
    
    std::cout << '\n';

    temp = bst.search(2);
    if(temp) std::cout << "found!\n";
    else std::cout << "not found!\n";

    return 0;
}