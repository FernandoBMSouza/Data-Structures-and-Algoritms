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
    int getDimension();
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

int DiagonalMatrix::getDimension()
{
    return m_dimension;
}

int DiagonalMatrix::get(int row, int column)
{
    if(row == column) return m_diagonal[row];
    else return 0;
}

void DiagonalMatrix::set(int row, int column, int value)
{
    if(row == column)
        m_diagonal[row] = value;
}

void DiagonalMatrix::display()
{
    for (int row = 0; row < m_dimension; row++)
    {
        for (int column = 0; column < m_dimension; column++)
        {
            std::cout << get(row, column) << ' ';
        }
        std::cout << '\n';
    }
}

#endif