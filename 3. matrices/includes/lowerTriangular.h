#ifndef LOWER_TRIANGULAR_H
#define LOWER_TRIANGULAR_H
#define COLUMN_MAJOR

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
        return m_lowerTriangle[(row*(row-1) / 2) + column - 1];
#endif
#ifdef COLUMN_MAJOR 
        return m_lowerTriangle[((column-1) * m_dimension - ((column - 2) * (column-1)) / 2) + (row - 1)];
#endif
    }
    else return 0;
}

void LowerTriangularMatrix::set(int row, int column, int value)
{
    if (row >= column)
    {
#ifdef ROW_MAJOR 
        m_lowerTriangle[(row*(row-1) / 2) + column - 1] = value;
#endif
#ifdef COLUMN_MAJOR 
        m_lowerTriangle[((column-1) * m_dimension - ((column - 2) * (column-1)) / 2) + (row - 1)] = value;
#endif
    }
}

void LowerTriangularMatrix::display()
{
    for (int row = 1; row <= m_dimension; row++)
    {
        for (int column = 1; column <= m_dimension; column++)
        {
            if (row >= column)
            {
#ifdef ROW_MAJOR 
                std::cout << m_lowerTriangle[(row*(row-1) / 2) + column - 1] << ' ';
#endif
#ifdef COLUMN_MAJOR 
                std::cout << m_lowerTriangle[((column-1) * m_dimension - ((column - 2) * (column-1)) / 2) + (row - 1)] << ' ';
#endif
            }
            else std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }
}

#endif
