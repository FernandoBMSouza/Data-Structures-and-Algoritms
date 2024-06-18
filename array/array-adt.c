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
    printf("Elements are:\n");
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

void my_delete(struct Array* arr, int index)
{
    if(index >= arr->length || index < 0) return;

    for(int i = index; i < arr->length - 1; i++)
        arr->A[i] = arr->A[i+1];
    
    arr->length--;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int is_sorted(struct Array* arr)
{
    for(int i = 0; i < arr->length-1; i++)
    {
        if(arr->A[i] > arr->A[i+1])
            return 0;
    }
    return 1;   
}

int linear_search(struct Array* arr, int key)
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
    if(!is_sorted(arr)) return -1;

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

void reverse_aux(struct Array* arr)
{
    // Using auxiliar array
    int *aux = (int*)malloc(arr->length*sizeof(int));
    for(int i = 0, j = arr->length - 1; j >= 0;i++, j--)
        aux[i] = arr->A[j];
    for(int i = 0; i < arr->length; i++)
        arr->A[i] = aux[i];

    free(aux);
    aux = NULL;
}

void reverse(struct Array* arr)
{
    for(int i = 0, j = arr->length - 1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void shift_left(struct Array* arr)
{
    if(arr->length <= 1) return;

    for(int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i+1];

    arr->A[arr->length-1] = 0;
}

void shift_right(struct Array* arr)
{
    if(arr->length <= 1) return;

    for(int i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i-1]; 
        
    arr->A[0] = 0;
}

void rotate_left(struct Array* arr)
{
    if(arr->length <= 1) return;

    int temp = arr->A[0];
    for(int i = 0; i < arr->length; i++)
        arr->A[i] = arr->A[i+1];

    arr->A[arr->length-1] = temp;
}

void rotate_right(struct Array* arr)
{
    if(arr->length <= 1) return;

    int temp = arr->A[arr->length-1];
    for(int i = arr->length - 1; i > 0; i--)
        arr->A[i] = arr->A[i-1]; 
        
    arr->A[0] = temp;
}

void insert_sorted(struct Array* arr, int value)
{
    if(arr->length == arr->size || !is_sorted(arr)) return;

    int i = arr->length-1;
    while(i >= 0 && arr->A[i] > value)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = value;
    arr->length++;
}

void rearrange(struct Array* arr)
{
    int i = 0;
    int j = arr->length-1;

    while(i < j)
    {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if(i < j) swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array* merge(struct Array* arr1, struct Array* arr2)
{
    if(!is_sorted(arr1) || !is_sorted(arr2)) return NULL;

    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    if(arr3 == NULL) return NULL;

    arr3->A = (int*)malloc((arr1->size + arr2->size) * sizeof(int));
    if(arr3->A == NULL) 
    {
        free(arr3);
        return NULL;
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while(i < arr1->length && j < arr2->length)
    {
        if(arr1->A[i] < arr2->A[j]) 
            arr3->A[k++] = arr1->A[i++];
        else                        
            arr3->A[k++] = arr2->A[j++];
    }

    for(; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for(; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array* my_union(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    if(arr3 == NULL) return NULL;

    arr3->size = arr1->size + arr2->size;

    arr3->A = (int*)malloc((arr3->size) * sizeof(int));
    if(arr3->A == NULL) 
    {
        free(arr3);
        return NULL;
    }

    int i = 0;
    int j = 0;
    int k = 0;
    
    if(is_sorted(arr1) && is_sorted(arr2))
    {
        while(i < arr1->length && j < arr2->length)
        {
            if(arr1->A[i] < arr2->A[j])
                arr3->A[k++] = arr1->A[i++];
            else if(arr1->A[i] > arr2->A[j])
                arr3->A[k++] = arr2->A[j++];
            else
            {
                arr3->A[k++] = arr1->A[i++];
                j++;
            }
        }

        for(; i < arr1->length; i++)
            arr3->A[k++] = arr1->A[i];

        for(; j < arr2->length; j++)
            arr3->A[k++] = arr2->A[j];
    }
    else
    {
        for(int i = 0; i < arr1->length; i++)
            arr3->A[k++] = arr1->A[i];
        
        for(int i = 0; i < arr2->length; i++)
            if(linear_search(arr1, arr2->A[i]) == -1)
                arr3->A[k++] = arr2->A[i];
    }

    arr3->length = k;
    return arr3;
}

struct Array* intersection(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    if(arr3 == NULL) return NULL;

    arr3->size = arr1->size + arr2->size;

    arr3->A = (int*)malloc((arr3->size) * sizeof(int));
    if(arr3->A == NULL) 
    {
        free(arr3);
        return NULL;
    }

    int i = 0;
    int j = 0;
    int k = 0;
    
    if(is_sorted(arr1) && is_sorted(arr2))
    {
        while(i < arr1->length && j < arr2->length)
        {
            if(arr1->A[i] < arr2->A[j]) i++;
            else if(arr1->A[i] > arr2->A[j]) j++;
            else
            {
                arr3->A[k++] = arr1->A[i++];
                j++;
            }
        }
    }
    else
    {
        for(int i = 0; i < arr1->length; i++)
            if(linear_search(arr2, arr1->A[i]) != -1)
                arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    return arr3;
}

struct Array* difference(struct Array* arr1, struct Array* arr2)
{
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    if(arr3 == NULL) return NULL;

    arr3->size = arr1->size + arr2->size;

    arr3->A = (int*)malloc((arr3->size) * sizeof(int));
    if(arr3->A == NULL) 
    {
        free(arr3);
        return NULL;
    }

    int i = 0;
    int j = 0;
    int k = 0;
    
    if(is_sorted(arr1) && is_sorted(arr2))
    {
        while(i < arr1->length && j < arr2->length)
        {
            if(arr1->A[i] < arr2->A[j])
                arr3->A[k++] = arr1->A[i++];
            else if(arr1->A[i] > arr2->A[j])
                j++;
            else
            {
                i++;
                j++;
            }
        }

        for(; i < arr1->length; i++)
            arr3->A[k++] = arr1->A[i];
    }
    else
    {
        for(int i = 0; i < arr1->length; i++)
            if(linear_search(arr2, arr1->A[i]) == -1)
                arr3->A[k++] = arr1->A[i];
    }

    arr3->length = k;
    return arr3;
}

int main()
{
    struct Array arr;
    int option = 0;
    int x,index;

    printf("Enter array size: ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));
    if(arr.A == NULL) 
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    arr.length = 0;
    do
    {
        printf("Enter array length: ");
        scanf("%d", &arr.length);
    } while (arr.length > arr.size || arr.length < 0);
    
    printf("Enter all elements: ");
    for(int i = 0; i < arr.length; i++)
        scanf("%d", &arr.A[i]);

    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1: 
                printf("Enter element: ");
                scanf("%d",&x);

                printf("Enter index: ");
                scanf("%d",&index);

                insert(&arr,index,x);
            break;
            case 2: 
                printf("Enter index ");
                scanf("%d",&index);

                printf("Deleted element is %d\n", arr.A[index]);
                my_delete(&arr,index);
            break;
            case 3:
                printf("Enter element: ");
                scanf("%d",&x);

                index = linear_search(&arr,x);
                printf("Element index: %d",index);
            break;
            case 4: printf("Sum is %d\n",sum(&arr)); break;
            case 5: display(&arr); break;
            default: 
                option = 6; 
                printf("Exiting the program.\n");
            break;
        }
    }while(option != 6);

    free(arr.A);
    arr.A = NULL;

    return 0;
}