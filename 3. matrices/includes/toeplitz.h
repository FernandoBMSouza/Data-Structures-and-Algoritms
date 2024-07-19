#ifndef TOEPLITZ_H
#define TOEPLITZ_H

#include <iostream>

class ToeplitzMatrix
{
private:
    int m_dimension = 0;
    int* m_matrix = nullptr;

public:
    ToeplitzMatrix(int dimension);
    ~ToeplitzMatrix();
    int get(int row, int column);
    void set(int row, int column, int value);
    void display();
    int getDimension();
};

ToeplitzMatrix::ToeplitzMatrix(int dimension)
{
    this->m_dimension = dimension;
    m_matrix = new int[2 * m_dimension - 1];
}

ToeplitzMatrix::~ToeplitzMatrix()
{
    delete[] m_matrix;
}

int ToeplitzMatrix::getDimension()
{
    return m_dimension;
}

int ToeplitzMatrix::get(int row, int column)
{
    if(row <= column) // UPPER TRIANGLE
    {
        return m_matrix[column - row];
    }
    else // LOWER TRIANGLE
    {
        return m_matrix[m_dimension + row - column - 1];
    }
}

void ToeplitzMatrix::set(int row, int column, int value)
{
    if(row <= column && row == 0) // UPPER TRIANGLE
    {
        m_matrix[column - row] = value;
    }
    else if (column < row && column == 0) // LOWER TRIANGLE
    {
        m_matrix[m_dimension + row - column - 1] = value;
    }
}

void ToeplitzMatrix::display()
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
