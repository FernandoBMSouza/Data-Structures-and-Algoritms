#ifndef UPPER_TRIANGULAR_H
#define UPPER_TRIANGULAR_H
#define COLUMN_MAJOR

#include <iostream>

class UpperTriangularMatrix
{
private:
    int m_dimension = 0;
    int* m_upperTriangle = nullptr;

public:
    UpperTriangularMatrix(int dimension);
    ~UpperTriangularMatrix();
    int get(int row, int column);
    void set(int row, int column, int value);
    void display();
    int getDimension();
};

UpperTriangularMatrix::UpperTriangularMatrix(int dimension)
{
    this->m_dimension = dimension;
    m_upperTriangle = new int[(m_dimension * (m_dimension + 1)) / 2];
}

UpperTriangularMatrix::~UpperTriangularMatrix()
{
    delete[] m_upperTriangle;
}

int UpperTriangularMatrix::getDimension()
{
    return m_dimension;
}

int UpperTriangularMatrix::get(int row, int column)
{
    if (row <= column)
    {
#ifdef ROW_MAJOR 
        return m_upperTriangle[(row * m_dimension) - ((row * (row + 1)) / 2) + column - row];
#endif
#ifdef COLUMN_MAJOR 
        return m_upperTriangle[(column * (column - 1)) / 2 + row];
#endif
    }
    else return 0;
}

void UpperTriangularMatrix::set(int row, int column, int value)
{
    if (row <= column)
    {
#ifdef ROW_MAJOR 
        m_upperTriangle[(row * m_dimension) - ((row * (row + 1)) / 2) + column - row] = value;
#endif
#ifdef COLUMN_MAJOR 
        m_upperTriangle[(column * (column - 1)) / 2 + row] = value;
#endif
    }
}

void UpperTriangularMatrix::display()
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
