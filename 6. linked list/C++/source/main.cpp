#include "circularLinkedList.h"
#include <iostream>

int main()
{
    const int size = 5;
    int* values = new int[size] {5, 9, 3, 7, 1};
    CircularLinkedList<int> linkedList(values, size);

    linkedList.display();
    linkedList.remove(0);
    linkedList.display();

    delete[] values;
    return 0;
}