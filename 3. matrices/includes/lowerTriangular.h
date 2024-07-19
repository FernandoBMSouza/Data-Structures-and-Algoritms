#ifndef LOWER_TRIANGULAR_H
#define LOWER_TRIANGULAR_H
#define ROW_MAJOR

#include <iostream>

class LowerTriangularMatrix
{
private:
    int m_dimension = 0;
    int* m_lowerTriangle = nullptr;

public:
    LowerTriangularMatrix(int dimension);
    ~LowerTriangularMatrix();
    int get(int row, int column);
    void set(int row, int column, int value);
    void display();
    int getDimension();
};

LowerTriangularMatrix::LowerTriangularMatrix(int dimension)
{
    this->m_dimension = dimension;
    m_lowerTriangle = new int[(m_dimension * (m_dimension + 1)) / 2];
}

LowerTriangularMatrix::~LowerTriangularMatrix()
{
    delete[] m_lowerTriangle;
}

int LowerTriangularMatrix::getDimension()
{
    return m_dimension;
}

int LowerTriangularMatrix::get(int row, int column)
{
    if (row >= column)
    {
#ifdef ROW_MAJOR 
        return m_lowerTriangle[(row * (row + 1)) / 2 + column];
#endif
#ifdef COLUMN_MAJOR 
        return m_lowerTriangle[(row * m_dimension) - (row * (row - 1)) / 2 + column];
#endif
    }
    else return 0;
}

void LowerTriangularMatrix::set(int row, int column, int value)
{
    if (row >= column)
    {
#ifdef ROW_MAJOR 
        m_lowerTriangle[(row * (row + 1)) / 2 + column] = value;
#endif
#ifdef COLUMN_MAJOR 
        m_lowerTriangle[(row * m_dimension) - (row * (row - 1)) / 2 + column] = value;
#endif
    }
}

void LowerTriangularMatrix::display()
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
