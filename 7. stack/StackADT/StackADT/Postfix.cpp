#include "LinkedListStack.h"
#include "Postfix.h"
#include <iostream>

namespace Postfix
{
	bool isOperand(char x)
	{
		return !(x == '+' || x == '-' || x == '*' || x == '/');
	}

	int precedence(char x)
	{
		switch (x)
		{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default: return 0;
		}
	}

	char* convert(const char* infix)
	{
		// ArrayStack<char> stack(std::strlen(infix));
		LinkedListStack<char> stack;
		char* postfix = new char[std::strlen(infix) + 1]; //um espaço a mais para o \0 null character

		int i = 0;
		int j = 0;
		while (infix[i] != '\0')
		{
			if(isOperand(infix[i]))
			{
				postfix[j++] = infix[i++];
			}
			else
			{
				if (precedence(infix[i]) > precedence(stack.stackTop()))
					stack.push(infix[i++]);
				else
					postfix[j++] = stack.pop();
			}
		}

		while (!stack.isEmpty())
			postfix[j++] = stack.pop();

		postfix[j] = '\0';
		return postfix;
	}
}