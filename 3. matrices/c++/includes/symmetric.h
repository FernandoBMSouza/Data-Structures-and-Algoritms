#ifndef SYMMETRIC_H
#define SYMMETRIC_H

#include <iostream>

class SymmetricMatrix
{
private:
    int m_dimension = 0;
    int* m_lowerTriangle = nullptr;

public:
    SymmetricMatrix(int dimension);
    ~SymmetricMatrix();
    int get(int row, int column);
    void set(int row, int column, int value);
    void display();
    int getDimension();
};

SymmetricMatrix::SymmetricMatrix(int dimension)
{
    this->m_dimension = dimension;
    m_lowerTriangle = new int[m_dimension * (m_dimension + 1) / 2];
}

SymmetricMatrix::~SymmetricMatrix()
{
    delete[] m_lowerTriangle;
}

int SymmetricMatrix::getDimension()
{
    return m_dimension;
}

int SymmetricMatrix::get(int row, int column)
{
    if (row >= column)
        return m_lowerTriangle[(row * (row + 1)) / 2 + column];
    else
        return m_lowerTriangle[(column * (column + 1)) / 2 + row];
}

void SymmetricMatrix::set(int row, int column, int value)
{
    if (row >= column) 
        m_lowerTriangle[(row * (row + 1)) / 2 + column] = value;
    else 
        m_lowerTriangle[(column * (column + 1)) / 2 + row] = value;
}

void SymmetricMatrix::display()
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
