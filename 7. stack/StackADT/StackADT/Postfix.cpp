#include "LinkedListStack.h"
#include "Postfix.h"
#include <iostream>

namespace Postfix
{
	bool isOperand(char x)
	{
		return !(x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^');
	}

	int outPrecedence(char x)
	{
		switch (x)
		{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 3;
		case '^': return 6;
		case '(': return 7;
		case ')': return 0;
		default: return -1;
		}
	}

	int inPrecedence(char x)
	{
		switch (x)
		{
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 4;
		case '^': return 5;
		case '(': return 0;
		default: return -1;
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
				if (stack.isEmpty() || outPrecedence(infix[i]) > inPrecedence(stack.stackTop()))
				{
					stack.push(infix[i++]);
				}
				else if (outPrecedence(infix[i]) == inPrecedence(stack.stackTop()))
				{
					stack.pop();
				}
				else
				{
					postfix[j++] = stack.pop();
				}
			}
		}

		while (!stack.isEmpty() && stack.stackTop() != ')')
			postfix[j++] = stack.pop();

		postfix[j] = '\0';
		return postfix;
	}

	int evaluate(char* postfix)
	{
		LinkedListStack<int> stack;

		for (int i = 0; postfix[i] != '\0'; i++)
		{
			if (isOperand(postfix[i]))
			{
				int value = postfix[i] - '0';
				stack.push(value);
			}
			else
			{
				int v2 = stack.pop();
				int v1 = stack.pop(); 

				switch (postfix[i])
				{
				case '+': stack.push(v1 + v2); break;
				case '-': stack.push(v1 - v2); break;
				case '*': stack.push(v1 * v2); break;
				case '/': stack.push(v1 / v2); break;
				}
			}
		}
		return stack.pop();
	}
}