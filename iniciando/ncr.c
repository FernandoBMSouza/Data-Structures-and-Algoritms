#include <stdio.h>

int fact(int n)
{
    if(n==0) return 1;
    return fact(n-1)*n;
}

int nCr(int n,int r)
{
    int num = fact(n);
    int den = fact(r) * fact(n-r);

    return num/den;
}

int ncr_recursive(int n, int r)
{
    if(r==0 || n==r)  
        return 1;
    return ncr_recursive(n-1,r-1) + ncr_recursive(n-1,r);
}

int main()
{
    printf("%d\n", ncr_recursive(5,3));
    return 0;
}