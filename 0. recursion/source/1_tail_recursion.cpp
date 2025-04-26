#include <iostream>

// Recursion
// time: O(n)
// space: O(n), são n activation recalls da stack

int fun1(int n)
{
    if(n > 0)
    {
        printf("%d", n);
        fun1(n-1);
    }
}

// Loop iterations
// time: O(n)
// space: O(1)

int fun2(int n)
{
    while(n > 0)
    {
        printf("%d", n);
        n--;
    }
}

int main()
{
    int x = 3;
    fun2(x);
    return 0;
}