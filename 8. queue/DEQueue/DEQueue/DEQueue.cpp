#include "DEQueueLinkedList.h"
#include <iostream>

int main()
{
    DEQueueLinkedList deq;
    deq.enqueueRear(10);
    deq.enqueueRear(20);
    deq.enqueueRear(30);
    deq.enqueueRear(40);
    deq.display();

    deq.enqueueFront(2);
    deq.enqueueFront(1);
    deq.display();

    deq.dequeueFront();
    deq.dequeueFront();
    deq.display();

    deq.dequeueRear();
    deq.dequeueRear();
    deq.display();

    return 0;

}