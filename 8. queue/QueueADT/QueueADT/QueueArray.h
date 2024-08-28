#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

class QueueArray
{
public:
	QueueArray(int size);
	~QueueArray();
	void enqueue(int value);
	int dequeue();
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
