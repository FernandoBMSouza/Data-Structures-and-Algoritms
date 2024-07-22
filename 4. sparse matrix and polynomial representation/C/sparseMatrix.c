#include <stdio.h>
#include <stdlib.h>

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

void displayTable(struct SparseMatrix* sparseMatrix)
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

void display(struct SparseMatrix* sparseMatrix)
{
    int k = 0;
    for(int i = 0; i < sparseMatrix->rows; i++)
    {
        for(int j = 0; j < sparseMatrix->columns; j++)
        {
            if(i == sparseMatrix->elements[k].row && j == sparseMatrix->elements[k].column)
            {
                printf("%d ", sparseMatrix->elements[k++].value);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

struct SparseMatrix* add(struct SparseMatrix* firstMatrix, struct SparseMatrix* secondMatrix)
{
    if(firstMatrix->rows != secondMatrix->rows || firstMatrix->columns != secondMatrix->columns)
    {
        return NULL;
    }

    struct SparseMatrix* sum = (struct SparseMatrix*)malloc(sizeof(struct SparseMatrix));
    sum->elements = (struct Element*)malloc((firstMatrix->numberOfValues + secondMatrix->numberOfValues) * (sizeof(struct Element)));

    int i = 0;
    int j = 0;
    int k = 0;
    while(i < firstMatrix->numberOfValues && j < secondMatrix->numberOfValues)
    {
        if(firstMatrix->elements[i].row < secondMatrix->elements[j].row)
        {
            sum->elements[k++] = firstMatrix->elements[i++];
        }
        else if(firstMatrix->elements[i].row > secondMatrix->elements[j].row)
        {
            sum->elements[k++] = secondMatrix->elements[j++];
        }
        else
        {
            if(firstMatrix->elements[i].column < secondMatrix->elements[j].column)
            {
                sum->elements[k++] = firstMatrix->elements[i++];
            }
            else if(firstMatrix->elements[i].column > secondMatrix->elements[j].column)
            {
                sum->elements[k++] = secondMatrix->elements[j++];
            }
            else
            {
                sum->elements[k] = firstMatrix->elements[i++];
                sum->elements[k++].value += secondMatrix->elements[j++].value;
            }
        }
    }
    for(; i < firstMatrix->numberOfValues; i++)
    {
        sum->elements[k++] = firstMatrix->elements[i];
    }

    for(; j < firstMatrix->numberOfValues; j++)
    {
        sum->elements[k++] = secondMatrix->elements[j];
    }
    sum->rows = firstMatrix->rows;
    sum->columns = firstMatrix->columns;
    sum->numberOfValues = k;
    return sum;
}

int main()
{
    struct SparseMatrix matrix1, matrix2;
    struct SparseMatrix* result;
    create(&matrix1);
    printf("\n");
    create(&matrix2);
    printf("\n");
    result = add(&matrix1, &matrix2);

    printf("First Matrix: \n");
    display(&matrix1);
    printf("Second Matrix: \n");
    display(&matrix2);
    printf("Sum Matrix: \n");
    display(result);

    free(matrix1.elements);
    free(matrix2.elements);
    free(result->elements);
    free(result);
    return 0;
}