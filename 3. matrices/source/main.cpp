#include "diagonal.h"
#include <iostream>

int main()
{
    std::cout << "Creating Matrix: \n";
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
    int choice = 0;
    int row, column, value;
    do
    {    
        std::cout << "\n- - - Options - - -\n";
        std::cout << "1. Get \n";
        std::cout << "2. Set \n";
        std::cout << "3. Display \n\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter row index: ";
            std::cin >> row;
            std::cout << "Enter column index: ";
            std::cin >> column;
            std::cout << "Value returned: " << matrix.get(row, column) << '\n';
            break;
        case 2:
            std::cout << "Enter row index: ";
            std::cin >> row;
            std::cout << "Enter column index: ";
            std::cin >> column;
            std::cout << "Enter value: ";
            std::cin >> value;
            matrix.set(row, column, value);
            std::cout << "Value " << value << " inserted at position: (" << row << ", "<< column << ")\n";
            break;
        case 3: matrix.display(); break;
        default: choice = 0; break;
        }
    } while (choice != 0);
    std::cout << "Exiting application\n";    
    return 0;
}