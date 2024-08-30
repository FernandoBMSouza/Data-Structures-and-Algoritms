#ifndef DEQUEUE_ARRAY_H
#define DEQUEUE_ARRAY_H

class DEQueueArray
{
public:
	DEQueueArray(int size);
	~DEQueueArray();
	void enqueueFront(int value);
	void enqueueRear(int value);
	int dequeueFront();
	int dequeueRear();
	bool isEmpty() const;
	bool isFull() const;
	void display() const;

private:
	int size;
	int front;
	int rear;
	int* elements;
};

#endif