#include <stdio.h>

int recursive_pow(int m,int n)
{
    if(n == 0) return 1;
    return recursive_pow(m, n-1) * m;
}

int recursive_pow2(int m,int n)
{
    if(n == 0) return 1;
    
    if(n % 2 == 0)  return recursive_pow2(m*m, n/2);
    else            return m * recursive_pow2(m*m, (n-1)/2);  
}

int loop_pow(int m, int n)
{
    int pow = 1;
    for(int i = 0; i < n; i++)
        pow *= m;
    
    return pow;
}

int main()
{
    printf("Recursion: %d \n", recursive_pow2(2,5));
    printf("Loop: %d \n", loop_pow(2,5));
    return 0;
}