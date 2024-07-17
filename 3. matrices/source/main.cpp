#include ".\includes\diagonal.h"
#include <iostream>

int main()
{
    DiagonalMatrix matrix(5);

    matrix.set(1,1,5);
    matrix.set(2,2,8);
    matrix.set(3,3,9);
    matrix.set(4,4,12);
    matrix.set(5,5,22);
    
    matrix.display();

    std::cout << matrix.get(1,1) << '\n';
    
    return 0;
}