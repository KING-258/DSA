#include<stdio.h>
int main()
{
    int r, c;
    int a[80][80];
    int largest[80];
    int smallest[80];
    printf("Number of Rows");
    scanf("%d",&r);
    printf("Number of Columns");
    scanf("%d",&c);
    printf("Input Matrix \n");
    for (int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Matrix \n");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d \t",a[i][j]);
        }
        printf("\n");
    }
    printf("Largest \n");
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if(a[i][j]>largest[i])
            {
                largest[i]=a[i][j];
            }
        }
    }
    for (int i=0; i<r; i++)
    {
        printf("%d \t",largest[i]);
    }
    printf("\nSmallest\n");
    for(int i=0; i<r; i++)
    {
        smallest[i]=a[i][i];
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(a[i][j]<smallest[i])
            {
                smallest[i]=a[i][j];
            }
        }
    } 
    for(int i=0; i<r; i++)
    {
        printf("%d \t",smallest[i]);
    }
    return 0;
}