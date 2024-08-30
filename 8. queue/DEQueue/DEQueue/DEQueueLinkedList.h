#ifndef DEQUEUE_LINKED_LIST_H
#define DEQUEUE_LINKED_LIST_H

struct Node
{
	int value;
	Node* next;
};

class DEQueueLinkedList
{
public:
	DEQueueLinkedList();
	~DEQueueLinkedList();
	void enqueueFront(int value);
	void enqueueRear(int value);
	int dequeueFront();
	int dequeueRear();
	void display() const;
	bool isEmpty() const;

private:
	Node* front;
	Node* rear;
};

#endif