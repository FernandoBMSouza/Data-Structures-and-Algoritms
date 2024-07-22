#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>

class Element
{
public:
    int row;
    int column;
    int value;
};

class SparseMatrix
{
private:
    int rows;
    int columns;
    int numberOfValues;
    Element* elements;
public:
    SparseMatrix(int rows, int columns, int numberOfValues);
    ~SparseMatrix();
    SparseMatrix operator+(SparseMatrix& matrix);
    friend std::istream& operator>>(std::istream& input, SparseMatrix& matrix);
    friend std::ostream& operator<<(std::ostream& output, const SparseMatrix& matrix);
};

SparseMatrix::SparseMatrix(int rows, int columns, int numberOfValues)
{
    this->rows = rows;
    this->columns = columns;
    this->numberOfValues = numberOfValues;
    elements = new Element[this->numberOfValues];
}

SparseMatrix::~SparseMatrix()
{
    delete[] elements;
}

SparseMatrix SparseMatrix::operator+(SparseMatrix& matrix)
{
    if(rows != matrix.rows || columns != matrix.columns)
        throw std::invalid_argument("Matrix dimensions must match for addition.");

    SparseMatrix result(rows, columns, numberOfValues+matrix.numberOfValues);
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < numberOfValues && j < matrix.numberOfValues)
    {
        if(elements[i].row < matrix.elements[j].row)
            result.elements[k++] = elements[i++];
        else if(elements[i].row > matrix.elements[j].row)
            result.elements[k++] = matrix.elements[j++];
        else
        {
            if(elements[i].column < matrix.elements[j].column)
                result.elements[k++] = elements[i++];
            else if(elements[i].column > matrix.elements[j].column)
                result.elements[k++] = matrix.elements[j++];
            else
            {
                result.elements[k] = elements[i];
                result.elements[k++].value = elements[i++].value + matrix.elements[j++].value;
            }
        }
    }
    for(; i < numberOfValues; i++) result.elements[k++] = elements[i];
    for(; j < matrix.numberOfValues; j++) result.elements[k++] = matrix.elements[j];
    result.numberOfValues = k;
    return result;
}

std::istream& operator>>(std::istream& input, SparseMatrix& matrix)
{
    std::cout << "Enter non-zero values:\n";
    for(int i = 0; i < matrix.numberOfValues; i++)
    {
        std::cin >> matrix.elements[i].row 
                 >> matrix.elements[i].column
                 >> matrix.elements[i].value;
    }
    std::cout << '\n';
    return input;
}

std::ostream& operator<<(std::ostream& output, const SparseMatrix& matrix)
{
    int k = 0;
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            if(matrix.elements[k].row == i && matrix.elements[k].column == j)
            {
                std::cout << matrix.elements[k++].value << ' ';
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    return output;
}

#endif