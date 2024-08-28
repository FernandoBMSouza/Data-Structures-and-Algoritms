#include "QueueArray.h"
#include <iostream>

int main()
{
    QueueArray queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.display();

    queue.dequeue();
    queue.dequeue();

    queue.enqueue(50);
    queue.enqueue(60);

    queue.display();
}