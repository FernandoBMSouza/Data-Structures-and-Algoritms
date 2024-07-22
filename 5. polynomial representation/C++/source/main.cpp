#include "polynomial.h"
#include <iostream>

int main()
{
    Polynomial polynomial1(3);
    Polynomial polynomial2(5);
    
    std::cout << "Enter first polynomial: \n";
    std::cin >> polynomial1;
    std::cout << "Enter second polynomial: \n";
    std::cin >> polynomial2;

    Polynomial result = polynomial1 + polynomial2;

    std::cout << "First Polynomial:\n";
    std::cout << polynomial1 << '\n';
    std::cout << "Second Polynomial:\n";
    std::cout << polynomial2 << '\n';
    std::cout << "Result Polynomial:\n";
    std::cout << result << '\n';

    return 0;
}