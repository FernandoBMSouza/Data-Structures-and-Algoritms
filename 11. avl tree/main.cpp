#include "./includes/avlTree.h"
#include <iostream>

int main()
{
    avlTree avl;
    avl.setRoot(avl.rInsert(avl.getRoot(), 10));
    avl.rInsert(avl.getRoot(), 15);
    avl.rInsert(avl.getRoot(), 20);

    std::cout << "Root: " << avl.getRoot()->data << '\n';
    return 0;
}