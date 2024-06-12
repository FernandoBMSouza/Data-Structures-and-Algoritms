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
    {
        printf("%d ", arr->A[i]);
    }

    printf("\n");
}

void add(struct Array* arr, int value)
{
    if(arr->length >= arr-> size) return;
    arr->A[arr->length++] = value;

    // Melhor para entender
    // arr->A[arr->length] = value;
    // arr->length++;
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
    if (arr.A == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
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

    add(&arr, 33);
    display(&arr);

    insert(&arr, 2, 60);
    display(&arr);

    free(arr.A);
    return 0;
}