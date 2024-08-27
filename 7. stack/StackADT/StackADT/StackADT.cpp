#include "Postfix.h"
#include <iostream>

int main()
{
    const char* infix = "3*5+6/2-4";
    char* postfix = Postfix::convert(infix);

    std::cout << "Infix: " << infix << '\n';
    std::cout << "Postfix: " << postfix << '\n';
    std::cout << "Evaluation: " << Postfix::evaluate(postfix) << '\n';

    delete[] postfix;

    return 0;
}