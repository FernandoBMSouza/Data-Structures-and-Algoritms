#include <iostream>

int exponent_recursion(int base, int power)
{
    if(power <= 0)
        return 1;
    return exponent_recursion(base, power - 1) * base;
}

int exponent_recursion_optimized(int base, int power)
{
    if(power <= 0)
        return 1;

    if(power % 2 == 0)
        return exponent_recursion_optimized(base * base, power/2);
    else
        return base * exponent_recursion_optimized(base * base, (power - 1) / 2);
}

int exponent_iterative(int base, int power)
{
    int result = 1;
    while(power >= 1)
    {
        result *= base;
        power--;
    }
    return result;
}

int main()
{
    std::cout << exponent_iterative(2, 9) << '\n';
    return 0;
}