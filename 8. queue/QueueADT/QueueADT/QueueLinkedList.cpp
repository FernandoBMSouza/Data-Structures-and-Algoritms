#include "QueueLinkedList.h"
#include <iostream>

QueueLinkedList::QueueLinkedList()
{
	front = rear = nullptr;
}

QueueLinkedList::~QueueLinkedList()
{
	while (front)
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
}

void QueueLinkedList::enqueue(int value)
{
	Node* node = new Node;
	node->value = value;
	node->next = nullptr;

	if (front == nullptr)
	{
		front = rear = node;
	}
	else
	{
		rear->next = node;
		rear = node;
	}
}

int QueueLinkedList::dequeue()
{
	int aux = -1;

	if (isEmpty())
	{
		std::cout << "queue is empty!\n";
	}
	else
	{
		aux = front->value;
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	return aux;
}

void QueueLinkedList::display() const
{
	if (isEmpty())
	{
		std::cout << "queue is empty!\n";
		return;
	}

	Node* aux = front;
	while (aux)
	{
		std::cout << aux->value << ' ';
		aux = aux->next;
	}
	std::cout << '\n';
}

bool QueueLinkedList::isEmpty() const
{
	return !front;
}