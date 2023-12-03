#include <stdio.h>
int main()
{
    int a;
    int arr[50][50];
    int b;
    int c = 0;
    int brr[50][50];
    printf("Input Array Size\n");
    scanf("%d", &a);
    printf("Input Elements\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (arr[i][j] != 0)
            {
                c++;
            }
        }
    }
    printf("Number of Values is %d \n", c);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("Sparse Matrix Represntation as 2-D Array\n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (arr[i][j] != 0)
            {
                brr[0][b] = i + 1;
                brr[1][b] = j + 1;
                brr[2][b] = arr[i][j];
                b++;
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", brr[i][j]);
        }
        printf("\n");
    }
    return 0;
}