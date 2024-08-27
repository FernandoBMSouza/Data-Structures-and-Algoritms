#ifndef POSTFIX_H
#define POSTFIX_H

namespace Postfix
{
	bool isOperand(char x);
	int precedence(char x);
	char* convert(const char* expression);
	int evaluate(char* postfixExpression);
}

#endif
