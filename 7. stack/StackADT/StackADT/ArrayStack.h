#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>

template <typename T>
class ArrayStack
{
public:
	ArrayStack(int size);
	~ArrayStack();

	void push(T value);
	T pop();
	T peek(int index);
	T stackTop();
	bool isEmpty();
	bool isFull();

private:
	struct Stack
	{
		int size;
		int top;
		T* elements;
	};
	Stack* stack;
};

template <typename T>
ArrayStack<T>::ArrayStack(int size)
{
	stack = new Stack;
	stack->size = size;
	stack->top = -1;
	stack->elements = new T[size];
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
	delete[] stack->elements;
	stack->elements = nullptr;

	delete stack;
	stack = nullptr;
}

template <typename T>
void ArrayStack<T>::push(T value)
{
	if (!isFull())
		stack->elements[++stack->top] = value;
	else
		std::cout << "stack overflow\n";
}

template <typename T>
T ArrayStack<T>::pop()
{
	if (isEmpty())
	{
		std::cout << "stack underflow\n";
		return -1;
	}

	T value = stack->elements[stack->top--];
	return value;		
}

template <typename T>
T ArrayStack<T>::peek(int position)
{
	if (stack->top - position + 1 < 0 || position < 1)
	{
		std::cout << "invalid index\n";
		return -1;
	}
	return stack->elements[stack->top - position + 1];
}

template <typename T>
T ArrayStack<T>::stackTop()
{
	if (stack->top == -1) return -1;

	return stack->elements[stack->top];
}

template <typename T>
bool ArrayStack<T>::isEmpty()
{
	return stack->top == -1;
}

template <typename T>
bool ArrayStack<T>::isFull()
{
	return stack->top == stack->size - 1;
}

#endif