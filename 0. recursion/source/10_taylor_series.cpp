#include <iostream>

double taylor_series_recursion(double x, double n)
{
    static double p = 1;
    static double f = 1;
    double r = 0;

    if(n <= 0)
        return 1;
    else
        r = taylor_series_recursion(x, n - 1);
        p *= x;
        f *= n;
        return r + p / f;
}

double taylor_series_iterative(double x, double n)
{
    double r = 1;
    double num = 1;
    double den = 1;

    for (int i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        r += num/den;
    }
    return r;
}

double horners_rule_recursion(double x, double n)
{
    static double s = 1;
    if(n <= 0)
        return s;
    s = 1 + x/n * s;
    return horners_rule_recursion(x, n - 1);
}

double horners_rule_iterative(double x, double n)
{
    double s = 1;
    for(;n > 0; n--)
        s = 1 + x/n * s;
    return s;
}

int main()
{
    std::cout << taylor_series_iterative(1, 10) << '\n';
    return 0;
}