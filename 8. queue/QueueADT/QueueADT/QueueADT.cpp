#include "QueueLinkedList.h"
#include <iostream>

int main()
{
    QueueLinkedList queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    queue.display();

    std::cout << queue.isEmpty();
}