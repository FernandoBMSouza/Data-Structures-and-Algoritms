#include <iostream>

// Time: O(n), Space: O(n)
int sum_recursion(int n)
{
    if(n <= 0) 
        return 0;
    return sum_recursion(n - 1) + n;
}

// Time: O(n), Space: O(1)
int sum_loop(int n)
{
    int result = 0;
    for(int i = 0; i <= n; i++)
        result += i;
    return result;
}

// Time: O(1), Space: O(1)
int sum(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int value = 5;
    std::cout << sum(value) << '\n';
    return 0;
}