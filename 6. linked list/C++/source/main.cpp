#include "linkedList.h"
#include <iostream>

int main()
{
    const int size = 6;
    int* values = new int[size] {5, 9, 3, 7, 1, 6};
    LinkedList<int> linkedList(values, size);

    std::cout<<linkedList.length()<<'\n';
    linkedList.display();
    linkedList.middleNode3();
    

    delete[] values;
    return 0;
}