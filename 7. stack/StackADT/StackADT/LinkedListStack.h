#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};

template <typename T>
class LinkedListStack
{
public:
	LinkedListStack();
	~LinkedListStack();

	void push(T value);
	void display() const;
	T pop();
	T peek(int index);
	T stackTop();
	bool isEmpty();
	bool isFull();

private:
	Node<T>* top;
};

template <typename T>
LinkedListStack<T>::LinkedListStack()
{
	top = nullptr;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack()
{
	while (top)
	{
		Node<T>* toDelete = top;
		top = top->next;
		delete toDelete;
	}
}

template <typename T>
void LinkedListStack<T>::display() const
{
	Node<T>* current = top;
	while (current)
	{
		std::cout << current->data << ' ';
		current = current->next;
	}
	std::cout << '\n';
}

template <typename T>
void LinkedListStack<T>::push(T value)
{
	Node<T>* newNode = new Node<T>;
	if (newNode == nullptr)
	{
		std::cout << "stack overflow\n";
	}
	else
	{
		newNode->data = value;
		newNode->next = top;
		top = newNode;
	}
}

template <typename T>
T LinkedListStack<T>::pop()
{
	if (top == nullptr)
	{
		std::cout << "stack is empty\n";
		return -1;
	}
	else
	{
		Node<T>* toPop = top;
		T value = toPop->data;
		top = top->next;
		delete toPop;
		return value;
	}
}

template <typename T>
T LinkedListStack<T>::peek(int position)
{
	Node<T>* current = top;

	for (int i = 0;current && i < position-1; i++)
		current = current->next;

	if (current) return current->data;
	else return -1;
}

template <typename T>
T LinkedListStack<T>::stackTop()
{
	if (top != nullptr) return top->data;
	else return -1;
}

template <typename T>
bool LinkedListStack<T>::isEmpty()
{
	return (top == nullptr);
}

template <typename T>
bool LinkedListStack<T>::isFull()
{
	Node<T>* testNode = new Node<T>;
	bool result = testNode ? false : true;
	delete testNode;
	return result;
}

#endif