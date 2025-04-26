#include <iostream>

int funA(int n);
int funB(int n);

int main()
{
    int x = 20;
    funA(x);
    return 0;
}

int funA(int n)
{
    if(n > 0)
    {
        std::cout << n << ' ';
        funB(n - 1);
    }
}

int funB(int n)
{
    if(n > 1)
    {
        std::cout << n << ' ';
        funA(n / 2);
    }
}