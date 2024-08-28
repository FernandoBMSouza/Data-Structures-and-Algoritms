#include "QueueArray.h"
#include <iostream>

QueueArray::QueueArray(int size)
{
	this->size = size;
	elements = new int[size];
	front = rear = 0;
}

QueueArray::~QueueArray()
{
	delete[] elements;
}

void QueueArray::enqueue(int value)
{
	if (isFull())
		std::cout << "queue is full!\n";
	else
		elements[++rear % size] = value;
}

int QueueArray::dequeue()
{
	int aux = -1;

	if (isEmpty())
		std::cout << "queue is empty!\n";
	else
		aux = elements[++front % size];

	return aux;
}

bool QueueArray::isEmpty() const
{
	return (front == rear);
}

bool QueueArray::isFull() const 
{
	return ((rear + 1) % size == front);
}

void QueueArray::display() const
{
	int i = front + 1;
	do
	{
		std::cout << elements[i] << ' ';
		i = (i + 1) % size;
	} while (i != (rear + 1) % size);
	
	std::cout << '\n';
}
