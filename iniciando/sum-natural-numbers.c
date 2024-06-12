#include <stdio.h>

int recursiveSum(int n)
{
    if(n == 0) return 0;
    else return recursiveSum(n - 1) + n;
}

int formulaSum(int n)
{
    return ( n * (n + 1) ) / 2;
}

int loopSum(int n)
{
    int sum = 0;
    for(int i = 0; i <= n; i++)
        sum += i;
    return sum;
}

int main()
{
    printf("Recursive: %d \n", recursiveSum(10));
    printf("Formula: %d \n", formulaSum(10));
    printf("Loop: %d \n", loopSum(10));
    return 0;
}