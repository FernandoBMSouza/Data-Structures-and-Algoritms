#define COLUMN_MAJOR

#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int* A;
    int n;
};

void Set(struct Matrix *m,int i,int j,int x)
{
    if(i >= j)
    {
#ifdef ROW_MAJOR
        m->A[i*(i-1)/2+j-1] = x;
#endif
#ifdef COLUMN_MAJOR
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j] = x;
#endif
    }
}

int Get(struct Matrix m,int i,int j)
{
    if(i >= j)
    {
#ifdef ROW_MAJOR
        return m.A[i*(i-1)/2+j-1];
#endif
#ifdef COLUMN_MAJOR
        return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j];
#endif
    }
    else return 0;
}

void Display(struct Matrix m)
{
    int i,j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i>=j)
            {
#ifdef ROW_MAJOR
                printf("%d ",m.A[i*(i-1)/2+j-1]);
#endif
#ifdef COLUMN_MAJOR
                printf("%d ",m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);
#endif
            } 
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Matrix m;

    printf("Enter Dimension: ");
    scanf("%d", &m.n);
    m.A = (int*)malloc(m.n*(m.n+1)/2*sizeof(int));

    printf("Enter all elements: ");
    for(int i = 1; i <= m.n; i++)
    {
        for(int j = 1; j <= m.n; j++)
        {
            int x;
            scanf("%d", &x);
            Set(&m, i, j, x);
        }
    }
    printf("\n\n");
    Display(m);
    free(m.A);
    return 0;
}