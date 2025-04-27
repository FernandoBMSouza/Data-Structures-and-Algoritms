#include <iostream>

int factorial_recursion(int n)
{
    if(n <= 0) 
        return 1;
    return factorial_recursion(n - 1) * n;
}

int factorial_iteration(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main()
{
    int value = 5;
    printf("%d", factorial_recursion(value));
    return 0;
}