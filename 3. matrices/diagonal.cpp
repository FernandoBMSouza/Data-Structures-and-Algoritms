#include <iostream>

struct Matrix
{
    int arr[10];
    int n;
};


void set(struct Matrix* matrix, int i, int j, int value)
{
    if(i == j) 
        matrix->arr[i] = value;
}

int get(struct Matrix* matrix, int i, int j)
{
    if(i == j) return matrix->arr[i];
    else return 0;
}

void display(struct Matrix* matrix)
{
    for(int i = 0; i < matrix->n; i++)
    {
        for(int j = 0; j < matrix->n; j++)
        {
            if(i == j)
                std::cout << matrix->arr[i] << ' ';
            else
                std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }
}

int main()
{
    struct Matrix matrix;
    matrix.n = 4;

    set(&matrix, 0,0,5);
    set(&matrix, 1,1,8);
    set(&matrix, 2,2,9);
    set(&matrix, 3,3,12);
    
    display(&matrix);

    std::cout << get(&matrix, 1,1) << '\n';
    
    return 0;
}