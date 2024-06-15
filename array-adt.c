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

    printf("\n");
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

void remove(struct Array* arr, int index)
{
    if(index >= arr->length || index < 0) return;

    for(int i = index; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linear_seach(struct Array* arr, int key)
{
    for(int i = 0; i < arr->length; i ++)
    {
        if(arr->A[i] == key)
        {
            // Optimizations

            // 1. Transposition
            // swap(&arr->A[i], &arr->A[i-1]);
            // return i-1;

            // 2. Move to Front/Head
            // if(i > 0)
            // { 
            //     swap(&arr->A[i], &arr->A[0]);
            //     return 0;
            // }

            return i;
        }
    }
    return -1;
}

int binary_search(struct Array* arr, int key)
{
    int low = 0;
    int high = arr->length-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr->A[mid] == key)     
            return mid;
        else if(arr->A[mid] > key) 
            high = mid - 1;
        else                       
            low = mid + 1;
    }
    return -1;
}

int recursive_binary_search(struct Array* arr, int low, int high, int key)
{
    if(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr->A[mid] == key)     
            return mid;
        else if(arr->A[mid] > key) 
            return recursive_binary_search(arr, low, mid - 1, key);
        else                
            return recursive_binary_search(arr, mid + 1, high, key);
    }
    return -1;
}

int get(struct Array* arr, int index)
{
    if(index < 0 || index >= arr->length) return -1;
    return arr->A[index];
}

void set(struct Array* arr, int index, int value)
{
    if(index >= 0 && index < arr->length)
        arr->A[index] = value;
}

int maximum(struct Array* arr)
{
    int max = arr->A[0];
    for(int i = 1; i < arr->length; i++)
    {
        if(arr->A[i] > max)
            max = arr->A[i];
    }
    return max;
}

int minimum(struct Array* arr)
{
    int min = arr->A[0];
    for(int i = 1; i < arr->length; i++)
    {
        if(arr->A[i] < min)
            min = arr->A[i];
    }
    return min;
}

int sum(struct Array* arr)
{
    int total = 0;
    for(int i = 0; i < arr->length; i++)
    {
        total += arr->A[i];
    }
    return total;
}

int recursive_sum(struct Array* arr, int n)
{
    if (n <= 0)
        return 0;
    return arr->A[n-1] + recursive_sum(arr, n-1);
}

float avg(struct Array* arr)
{
    //if(arr->length != 0)
    return (float)sum(arr) / arr->length;
}


int main()
{
    struct Array arr;

    printf("Enter array size: ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));
    if(arr.A == NULL) 
    {
        printf("Memory allocation failed\n");
        return -1;
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

    printf("hello world!\n");

    free(arr.A);
    arr.A = NULL;
    return 0;
}