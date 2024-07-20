#include <stdlib.h>
#include <stdio.h>

struct Element
{
    int row;
    int column;
    int value;
};

struct SparseMatrix
{
    int rows;
    int columns;
    int numberOfValues;
    struct Element* elements;
};

void create(struct SparseMatrix* sparseMatrix)
{
    printf("Enter number of rows: ");
    scanf("%d", &sparseMatrix->rows);
    printf("Enter number of columns: ");
    scanf("%d", &sparseMatrix->columns);
    printf("Enter number of non-zero elements: ");
    scanf("%d", &sparseMatrix->numberOfValues);

    sparseMatrix->elements = (struct Element*)malloc(sparseMatrix->numberOfValues * sizeof(struct Element));
    printf("Enter all non-zero elements (row column value): ");
    for(int i = 0; i < sparseMatrix->numberOfValues; i++)
    {
        scanf("%d %d %d", &sparseMatrix->elements[i].row,
                          &sparseMatrix->elements[i].column,
                          &sparseMatrix->elements[i].value);
    }
}

void display(struct SparseMatrix* sparseMatrix)
{
    printf(" ROW | COLUMN | VALUE \n");
    printf(" %d   | %d      | %d     \n", sparseMatrix->rows, sparseMatrix->columns, sparseMatrix->numberOfValues);
    for(int i = 0; i < sparseMatrix->numberOfValues; i++)
    {
        printf(" %d   | %d      | %d     \n", sparseMatrix->elements[i].row, 
                                              sparseMatrix->elements[i].column, 
                                              sparseMatrix->elements[i].value);
    }
}


int main()
{
    struct SparseMatrix matrix;
    create(&matrix);
    display(&matrix);
    free(matrix.elements);
    return 0;
}