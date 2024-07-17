#ifndef DIAGONAL_H
#define DIAGONAL_H

#include <iostream>

class DiagonalMatrix
{
private:
    int m_dimension = 0;
    int* m_diagonal = nullptr;

public:
    DiagonalMatrix(int dimension);
    ~DiagonalMatrix();
    int get(int row, int column);
    void set(int row, int column, int value);
    void display();
};

DiagonalMatrix::DiagonalMatrix(int dimension)
{
    this->m_dimension = dimension;
    m_diagonal = new int[m_dimension];
}

DiagonalMatrix::~DiagonalMatrix()
{
    delete[] m_diagonal;
}

int DiagonalMatrix::get(int row, int column)
{
    if(row == column) return m_diagonal[row - 1];
    else return 0;
}

void DiagonalMatrix::set(int row, int column, int value)
{
    if(row == column)
        m_diagonal[row - 1] = value;
}

void DiagonalMatrix::display()
{
    for(int column = 0; column < m_dimension; column++)
    {
        for(int row = 0; row < m_dimension; row++)
        {
            if(row == column) std::cout << m_diagonal[row] << ' ';
            else std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }
}

#endif