#include <iostream>

// Time: O(2^n)
// Space: O(n), altura da arvore + 1

int fun(int n)
{
    if(n > 0)
    {
        printf("%d", n);
        fun(n - 1);
        fun(n - 1);
    }
}

int main()
{
    int x = 3;
    fun(3);
    return 0;
}