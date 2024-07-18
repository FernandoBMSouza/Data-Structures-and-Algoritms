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
        return m_upperTriangle[((row-1) * m_dimension - ((row - 2) * (row-1)) / 2) + (column - 1)];
#endif
#ifdef COLUMN_MAJOR 
        return m_upperTriangle[(column*(column-1) / 2) + row - 1];
#endif
    }
    else return 0;
}

void UpperTriangularMatrix::set(int row, int column, int value)
{
    if (row <= column)
    {
#ifdef ROW_MAJOR 
        m_upperTriangle[((row-1) * m_dimension - ((row - 2) * (row-1)) / 2) + (column - 1)] = value;
#endif
#ifdef COLUMN_MAJOR 
        m_upperTriangle[(column*(column-1) / 2) + row - 1] = value;
#endif
    }
}

void UpperTriangularMatrix::display()
{
    for (int row = 1; row <= m_dimension; row++)
    {
        for (int column = 1; column <= m_dimension; column++)
        {
            if (row <= column)
            {
#ifdef ROW_MAJOR 
                std::cout << m_upperTriangle[((row-1) * m_dimension - ((row - 2) * (row-1)) / 2) + (column - 1)] << ' ';
#endif
#ifdef COLUMN_MAJOR 
                std::cout << m_upperTriangle[(column*(column-1) / 2) + row - 1] << ' ';
#endif
            }
            else std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }
}

#endif
