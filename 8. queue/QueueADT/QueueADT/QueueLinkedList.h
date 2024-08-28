#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

struct Node
{
	int value;
	Node* next;
};

class QueueLinkedList
{
public:
	QueueLinkedList();
	~QueueLinkedList();
	void enqueue(int value);
	int dequeue();
	void display() const;
	bool isEmpty() const;

private:
	Node* front = nullptr;
	Node* rear = nullptr;
};

#endif