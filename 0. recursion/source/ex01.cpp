#include <iostream>

//tail recursion example

int fun1(int n)
{
    if(n > 0)
    {
        printf("%d", n);
        fun1(n-1);
    }
}

int fun2(int n)
{
    if(n > 0)
    {
        fun2(n-1);
        printf("%d", n);
    }
}

int main()
{
    int x = 3;
    fun2(x);
    return 0;
}