#include <stdio.h>

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r = 0;

    if(n == 0) return(1);

    r = e(x, n-1);
    p *= x;
    f *= n;
    return r + p / f;
}


int main()
{
    printf("%lf \n", e(3,20));
    return 0;
}