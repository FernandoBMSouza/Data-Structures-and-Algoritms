#include <iostream>
#include <vector>

int fib(int n)
{
    if(n <= 1)
        return n;
    return fib(n-2) + fib(n-1);
}

int fib_iterative(int n)
{
    int t0 = 0;
    int t1 = 1;
    int s = 0;

    if(n <= 1)
        return n;

    for(int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int fib_memoization(int n)
{
    static std::vector<int> memo;

    if (memo.size() <= n) {
        memo.resize(n + 1, -1);
    }

    if(n <= 1)
    {
        memo[n] = n;
        return n;
    }
    else
    {
        if(memo[n - 2] == -1)
            memo[n - 2] = fib_memoization(n - 2);
        if(memo[n - 1] == -1)
            memo[n - 1] = fib_memoization(n - 1);
        
        memo[n] = memo[n - 1] + memo[n - 2];
        return memo[n];
    }
}

int main()
{
    std::cout << fib_memoization(10) << '\n';
    return 0;
}