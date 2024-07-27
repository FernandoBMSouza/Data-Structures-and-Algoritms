#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node* next;
} *first = NULL;

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

int maxValue(struct Node* p)
{
    int max = INT_MIN;
    while (p)
    {
        if(p->data > max) 
            max = p->data;

        p = p->next;
    }
    return max;
}

int recursiveMaxValue(struct Node* p)
{
    if(p == 0) return INT_MIN;
    int x = 0;
    x = recursiveMaxValue(p->next);
    return x > p->data ? x : p->data;
}

int minValue(struct Node* p)
{
    int min = INT_MAX;
    while (p)
    {
        if(p->data < min) 
            min = p->data;

        p = p->next;
    }
    return min;
}

int recursiveMinValue(struct Node* p)
{
    if(p == 0) return INT_MAX;
    int x = 0;
    x = recursiveMinValue(p->next);
    return x < p->data ? x : p->data;
}

struct Node* linearSearch(struct Node* p, int key)
{
    while (p != NULL)
    {
        if(key == p->data) return p;
        p = p->next;
    }
    return NULL;    
}

struct Node* recursiveLinearSearch(struct Node* p, int key)
{
    if(p == NULL) return NULL;
    if(p->data == key) return p;
    return recursiveLinearSearch(p->next, key);
}

struct Node* linearSearchMoveToHead(struct Node** head, int key)
{
    struct Node* p = *head;
    struct Node* q = NULL;

    while (p != NULL)
    {
        if(p->data == key)
        {
            if (q != NULL)
            {
                q->next = p->next;
                p->next = *head;
                *head = p;
            }
            return p;
        }

        q = p;
        p = p->next;
    }
    return NULL;    
}

void insert(struct Node** p, int index, int value)
{
    if(index < 0 || index > countNodes(*p)) 
        return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if(index == 0)
    {
        newNode->next = *p;
        *p = newNode;
    }
    else
    {
    struct Node* q = *p;

        for(int i = 0; i < index - 1; i++)
            q = q->next;
        
        newNode->next = q->next;
        q->next = newNode;
    }
}

int main()
{
    int arr[] = {3, 5, 7, 10, 15, 8, 12, 20};
    create(arr, 8);
    
    struct Node* temp = linearSearchMoveToHead(&first, 56);

    if(temp) printf("VALUE %d FOUND\n", temp->data);
    else printf("VALUE NOT FOUND\n");

    display(first);

    freeList(first);
    return 0;
}