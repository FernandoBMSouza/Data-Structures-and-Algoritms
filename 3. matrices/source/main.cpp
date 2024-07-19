#include "diagonal.h"
#include <iostream>

int main()
{
    int dimension;
    std::cout << "Enter dimension: ";
    std::cin >> dimension;

    DiagonalMatrix matrix(dimension);    

    std::cout<<"Enter all elements:\n";
    for(int i = 0; i < matrix.getDimension(); i++)
    {
        for (int j = 0; j < matrix.getDimension(); j++)
        {
            int x;
            std::cin >> x;
            matrix.set(i,j,x);
        }
    }

    std::cout << '\n';
    matrix.display();
    
    return 0;
}