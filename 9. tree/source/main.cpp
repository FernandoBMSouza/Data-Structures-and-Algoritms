#include <iostream>
#include "tree.h"

int main()
{
    Tree<int> t;

    t.createTree();

    std::cout << "HEIGHT: " << t.getHeight(t.getRoot()) << '\n';

    std::cout << "Nodes: "            << t.countNodes(t.getRoot()) << '\n';
    std::cout << "Leaf Nodes: "       << t.countLeafNodes(t.getRoot()) << '\n';
    std::cout << "Internal Nodes: "   << t.countInternalNodes(t.getRoot()) << '\n';
    std::cout << "Degree Two Nodes: " << t.countDegree2Nodes(t.getRoot()) << '\n';
    std::cout << "Degree One Nodes: " << t.countDegree2Nodes(t.getRoot()) << '\n';

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