#include <iostream>
#include "tree.h"

int main()
{
    Tree<int> t;

    t.createTree();

    std::cout << "\nHEIGHT: " << t.getHeight(t.getRoot());

    std::cout << "\nPRE ORDER: ";
    t.preOrder(t.getRoot());

    std::cout << "\nIN ORDER: ";
    t.inOrder(t.getRoot());

    std::cout << "\nPOST ORDER: ";
    t.postOrder(t.getRoot());

    std::cout << "\nLEVEL ORDER: ";
    t.levelOrder(t.getRoot());

    return 0;
}