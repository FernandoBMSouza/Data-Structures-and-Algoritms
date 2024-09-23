#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
public:
	Queue(int size);
	~Queue();
	void enqueue(const T& value);
	T dequeue();
	bool isEmpty() const;
	bool isFull() const;
	void display() const;

private:
	int size;
	int front;
	int rear;
	T* elements;
};

template<typename T>
Queue<T>::Queue(int size)
{
	this->size = size;
	elements = new T[size];
	front = rear = -1;
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] elements;
}

template<typename T>
void Queue<T>::enqueue(const T& value)
{
	if (isFull())
		std::cout << "queue is full!\n";
	else
		elements[(++rear) % size] = value;
}

template<typename T>
T Queue<T>::dequeue()
{
	if (isEmpty())
    {
		std::cout << "queue is empty!\n";
        return T();
    }
	else
    {
        return elements[(++front) % size];
    }
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return (front == rear);
}

template<typename T>
bool Queue<T>::isFull() const 
{
	return ((rear + 1) % size == front);
}

template<typename T>
void Queue<T>::display() const
{
	int i = front + 1;
	do
	{
		std::cout << elements[i] << ' ';
		i = (i + 1) % size;
	} while (i != (rear + 1) % size);
	
	std::cout << '\n';
}

#endif