#include<stdio.h>
int main()
{
    int r1, c1;
    int a[80][80];
    printf("Rows");
    scanf("%d",&r1);
    printf("Columns");
    scanf("%d",&c1);
    printf("Input Array");
    for (int i=0; i<r1; i++)
    {
        for (int j=0; j<c1; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=0; i<r1; i++)
    {
        for (int j=0; j<c1; j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    int r, c, e;
    printf("Element");
    scanf("%d",&e);
    printf("Position of Element in R and C");
    scanf("%d%d",&r,&c);
    for (int i=r1; i>=r; i--)
    {
        for (int j=c1; j>=c; j--)
        {
            a[r-1][c-1]=e;
        }
    }
    printf("New Matrix\n");
    for (int i=0; i<r1; i++)
    {
        for (int j=0; j<c1; j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}