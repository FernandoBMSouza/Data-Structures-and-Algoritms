#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int* A;
    int size;
    int length;
};

void display(struct Array* arr)
{
    printf("\nElements are:\n");
    for(int i = 0; i < arr->length; i++)
        printf("%d ", arr->A[i]);
}

void add(struct Array* arr, int value)
{
    if(arr->length >= arr-> size) return;
    arr->A[arr->length++] = value;
}

void insert(struct Array* arr, int index, int value)
{
    if(arr->length >= arr->size) return;
    if(index < 0 || index > arr->length) return;

    for(int i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i-1];
    }

    arr->A[index] = value;
    arr->length++;
}

int main()
{
    struct Array arr;

    printf("Enter array size: ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length = 0;

    int n = 0;

    do
    {
        printf("Enter array lenght: ");
        scanf("%d", &n);
    } while (n > arr.size || n < 0);

    arr.length = n;
    
    
    printf("Enter all elements: ");
    for(int i = 0; i < arr.length; i++)
        scanf("%d", &arr.A[i]);

    display(&arr);

    free(arr.A);
    return 0;
}