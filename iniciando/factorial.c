#include <stdio.h>

int recursive_factorial(int n)
{   
    if(n > 0) return recursive_factorial(n-1) * n;
    return 1;
}

int loop_factorial(int n)
{   
    int factorial = 1;
    for(int i = 1; i <= n; i++)
        factorial *= i;

    return factorial;
}

int main()
{
    printf("%d \n", recursive_factorial(5));
    printf("%d \n", loop_factorial(5));
    return 0;
}