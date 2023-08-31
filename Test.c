#include<stdio.h>
int main()
{
    int a[10][10];
    int r, c;
    printf("Number of Rows and Columns\n");
    scanf("%d%d",&r,&c);
    printf("Array");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            scanf("%d",& a[i][j]);
        }
    }
    printf("Matrix Form\n");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}