#include "./includes/avlTree.h"
#include <iostream>

int main()
{
    avlTree avl;
    avl.setRoot(avl.rInsert(avl.getRoot(), 10));
    avl.rInsert(avl.getRoot(), 20);
    avl.rInsert(avl.getRoot(), 30);
    avl.rInsert(avl.getRoot(), 25);
    avl.rInsert(avl.getRoot(), 28);
    avl.rInsert(avl.getRoot(), 27);
    avl.rInsert(avl.getRoot(), 5);

    std::cout << "Root: " << avl.getRoot()->data << '\n';
    avl.inOrder();
    std::cout << '\n';

    avl.deleteNode(avl.getRoot(), 28);

    avl.inOrder();
    std::cout << '\n';
 
    return 0;

}