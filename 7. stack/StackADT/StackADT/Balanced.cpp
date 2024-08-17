#include "Balanced.h"
#include "ArrayStack.h"
#include <cstring>

bool isBalanced(const char* expression)
{
    ArrayStack<char> stack(std::strlen(expression));
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            stack.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (stack.isEmpty()) return false;
            stack.pop();
        }
    }
    return stack.isEmpty();
}

bool isBalancedMoreSymbols(const char* expression)
{
    ArrayStack<char> stack(std::strlen(expression));
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            stack.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if (stack.isEmpty()) return false;

            char topChar = stack.pop();

            if (!((topChar == '(' && expression[i] == ')') ||
                  (topChar == '{' && expression[i] == '}') ||
                  (topChar == '[' && expression[i] == ']')))
            {
                return false;
            }
        }
    }
    return stack.isEmpty();
}
