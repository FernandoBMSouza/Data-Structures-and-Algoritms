#include <iostream>

//Recursion
int fun1(int n)
{
    if(n > 0)
    {
        fun1(n-1);
        printf("%d", n);
    }
}

//Loop (not too simple as in tail recursion)
int fun2(int n)
{
    int i = 1;
    while(i <= n)
    {
        printf("%d", i);
        i++;
    }
}

int main()
{
    int x = 3;
    fun2(x);
    return 0;
}