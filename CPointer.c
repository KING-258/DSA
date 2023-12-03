#include <stdio.h>
#include <stdlib.h>
void Multiply(int **a, int **b, int **c, int d, int e, int f, int g)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < g; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < e; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
}
int main()
{
    int a, b;
    int r, c;
    int **a1;
    int **a2;
    int **res;
    printf("Input Size of Matrix 1 R and C\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Input Size of Matrix 2 R and C\n");
    scanf("%d", &r);
    scanf("%d", &c);
    a1 = (int **)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        a1[i] = (int *)malloc(b * sizeof(int));
    }
    a2 = (int **)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++)
    {
        a2[i] = (int *)malloc(c * sizeof(int));
    }
    res = (int **)malloc(a * sizeof(int));
    for (int i = 0; i < a; i++)
    {
        res[i] = (int *)malloc(c * sizeof(int));
    }
    printf("Input Matrix 1\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }
    printf("Input Matrix 2\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }
    printf("Matrix 1\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            printf("%d\t", a1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", a2[i][j]);
        }
        printf("\n");
    }
    Multiply(a1, a2, res, a, b, r, c);
    printf("Result is :\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}