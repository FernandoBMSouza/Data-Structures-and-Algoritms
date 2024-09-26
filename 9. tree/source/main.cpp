#include <iostream>
#include "tree.h"

int main()
{
    Tree<int> t;

    t.createTree();

    std::cout << "HEIGHT: " << t.getHeight(t.getRoot()) << '\n';

    std::cout << "POST-ORDER: ";
    t.postOrderIterative(t.getRoot());
    std::cout << '\n';

    // std::cout << "\nPRE ORDER: ";
    // t.preOrder(t.getRoot());

    // std::cout << "\nIN ORDER: ";
    // t.inOrder(t.getRoot());

    // std::cout << "\nPOST ORDER: ";
    // t.postOrder(t.getRoot());

    // std::cout << "\nLEVEL ORDER: ";
    // t.levelOrder(t.getRoot());

    return 0;
}