#include <stdio.h>

//int x = 0;

int foo(int n)
{
    static int x = 0;
    if(n > 0)
    {
        x++;
        return foo(n-1) + x;
    }
    return 0;
}

int main()
{
    int a = 5;
    printf("%d", foo(a));
    return 0;
}