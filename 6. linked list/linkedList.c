#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
} *first;

void create(int* arr, int n)
{
    int i;
    struct Node* t;
    struct Node* last;

    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void freeList(struct Node* p)
{
    struct Node* temp;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        free(temp);
    }
}

void display(struct Node* p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void recursiveDisplay(struct Node* p)
{
    if(p != NULL)
    {
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
}

void reverseRecursiveDisplay(struct Node* p)
{
    if(p != NULL)
    {
        reverseRecursiveDisplay(p->next);
        printf("%d ", p->data);
    }
}

int countNodes(struct Node* p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int recursiveCountNodes(struct Node* p)
{
    if (p != NULL) return recursiveCountNodes(p->next) + 1;
    else return 0;
}

int sum(struct Node* p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p=p->next;
    }
    return sum;
}

int recursiveSum(struct Node* p)
{
    if (p) return recursiveSum(p->next) + p->data;
    else return 0;
}


int main()
{
    int arr[] = {3, 5, 7, 10, 15, 8, 12, 20};
    create(arr, 8);
    
    printf("Somatorio dos Nodes: %d\n", sum(first));
    freeList(first);
    return 0;
}