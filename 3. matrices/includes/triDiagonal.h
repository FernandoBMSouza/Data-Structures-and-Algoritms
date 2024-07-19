#ifndef TRI_DIAGONAL_H
#define TRI_DIAGONAL_H

#include <iostream>

class TriDiagonalMatrix
{
private:
    int m_dimension = 0;
    int* m_matrix = nullptr;

public:
    TriDiagonalMatrix(int dimension);
    ~TriDiagonalMatrix();
    int get(int row, int column);
    void set(int row, int column, int value);
    void display();
    int getDimension();
};

TriDiagonalMatrix::TriDiagonalMatrix(int dimension)
{
    this->m_dimension = dimension;
    m_matrix = new int[3 * m_dimension - 2];
}

TriDiagonalMatrix::~TriDiagonalMatrix()
{
    delete[] m_matrix;
}

int TriDiagonalMatrix::getDimension()
{
    return m_dimension;
}

int TriDiagonalMatrix::get(int row, int column)
{
    switch (row - column)
    {
    case -1: return m_matrix[2 * m_dimension + row - 1]; break;
    case  0: return m_matrix[m_dimension + row - 1];     break;
    case  1: return m_matrix[row - 1];                   break;
    default: return 0;                                   break;
    }
}

void TriDiagonalMatrix::set(int row, int column, int value)
{
    switch (row - column)
    {
    case -1: m_matrix[2 * m_dimension + row - 1] = value; break;
    case  0: m_matrix[m_dimension + row - 1] = value;     break;
    case  1: m_matrix[row - 1] = value;                   break;
    }
}

void TriDiagonalMatrix::display()
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
