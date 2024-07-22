#include "sparseMatrix.h"
#include <iostream>

int main()
{
    SparseMatrix matrix1(5,5,5);
    SparseMatrix matrix2(5,5,5);

    std::cin >> matrix1;
    std::cin >> matrix2;

    SparseMatrix sum = matrix1 + matrix2;

    std::cout << "First Matrix:\n" << matrix1;
    std::cout << "Second Matrix:\n" << matrix2;
    std::cout << "Result Matrix:\n" << sum;

    std::cout << '\n';
    return 0;
}