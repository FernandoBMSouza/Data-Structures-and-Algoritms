#include "DEQueueLinkedList.h"
#include <iostream>

DEQueueLinkedList::DEQueueLinkedList()
{
	front = rear = nullptr;
}

DEQueueLinkedList::~DEQueueLinkedList()
{
	while (front)
	{
		Node* aux = front;
		front = front->next;
		delete aux;
	}
}

void DEQueueLinkedList::display() const
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

bool DEQueueLinkedList::isEmpty() const
{
	return !front;
}

void DEQueueLinkedList::enqueueFront(int value)
{
	Node* node = new Node;
	node->value = value;
	node->next = nullptr;

	if (isEmpty())
	{
		front = rear = node;
	}
	else
	{
		node->next = front;
		front = node;
	}
}

void DEQueueLinkedList::enqueueRear(int value)
{
	Node* node = new Node;
	node->value = value;
	node->next = nullptr;

	if (isEmpty())
	{
		front = rear = node;
	}
	else
	{
		rear->next = node;
		rear = node;
	}
}

int DEQueueLinkedList::dequeueFront()
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

int DEQueueLinkedList::dequeueRear()
{
	int aux = -1;
	if (isEmpty())
	{
		std::cout << "queue is empty!\n";
		return aux;
	}
	else if (front == rear)
	{
		aux = rear->value;
		delete rear;
		front = rear = nullptr;
	}
	else
	{
		aux = rear->value;

		Node* temp = rear;
		rear = front;

		while (rear->next != temp)
			rear = rear->next;

		rear->next = nullptr;
		delete temp;
	}
	return aux;
}

