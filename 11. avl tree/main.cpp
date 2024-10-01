#include "./includes/avlTree.h"
#include <iostream>

int main()
{
    avlTree avl;
    avl.setRoot(avl.rInsert(avl.getRoot(), 10));
    avl.rInsert(avl.getRoot(), 5);
    avl.rInsert(avl.getRoot(), 2);

    std::cout << "Root: " << avl.getRoot()->data << '\n';
    return 0;
}