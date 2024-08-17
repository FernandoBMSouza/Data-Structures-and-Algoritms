#include "Postfix.h"
#include <iostream>

int main()
{
    const char* infix = "a+b*c-d/e";
    char* postfix = Postfix::convert(infix);

    std::cout << "Infix: " << infix << '\n';
    std::cout << "Postfix: " << postfix << '\n';

    // Depois de terminar de usar o array postfix, libere a mem�ria
    delete[] postfix;

    return 0;
}