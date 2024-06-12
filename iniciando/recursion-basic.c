#include <stdio.h>

// TAIL RECURSION
void foo1(int x)
{
    if(x > 0)
    {
        printf("%d ", x);
        foo1(x - 1);
    }
}

// HEAD RECURSION
void foo2(int x)
{
    if(x > 0)
    {
        foo2(x - 1);
        printf("%d ", x);
    }
}

int main()
{
    int x = 3;
    foo1(x);
    printf("\n");
    foo2(x);
    return 0;
}