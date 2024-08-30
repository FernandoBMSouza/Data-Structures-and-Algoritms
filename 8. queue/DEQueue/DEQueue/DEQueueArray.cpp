#include "DEQueueArray.h"
#include "iostream"

DEQueueArray::DEQueueArray(int size)
{
	this->size = size;
	elements = new int[size];
	front = rear = -1;
}

DEQueueArray::~DEQueueArray()
{
	delete[] elements;
}

void DEQueueArray::enqueueFront(int value)
{
	if (front == -1)
	{
		std::cout << "queue front is full!\n";
		return;
	}

	elements[front--] = value;
}

void DEQueueArray::enqueueRear(int value)
{
	if (isFull())
	{
		std::cout << "queue is full!\n";
		return;
	}

	elements[++rear] = value;
}

int DEQueueArray::dequeueFront()
{
	int aux = -1;

	if (isEmpty())
		std::cout << "queue is empty!\n";
	else
		aux = elements[++front];

	return aux;
}

int DEQueueArray::dequeueRear()
{
	int aux = -1;

	if (isEmpty())
		std::cout << "queue is empty!\n";
	else
		aux = elements[rear--];

	return aux;
}

bool DEQueueArray::isEmpty() const
{
	return (front == rear);
}

bool DEQueueArray::isFull() const 
{
	return rear >= size - 1;
}

void DEQueueArray::display() const
{
	if (isEmpty()) std::cout << "queue is empty!";
	for (int i = front + 1; i <= rear; i++)
	{
		std::cout << elements[i] << ' ';
	}

	std::cout << '\n';
}