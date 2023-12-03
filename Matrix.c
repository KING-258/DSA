#include <stdio.h>
int main()
{
    int a, b, r, c;
    int arr[80][80];
    int brr[80][80];
    int ans[80][80];
    printf("Input Size of Matrix 1 R and C");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Input Size of Matrix 2 R and C");
    scanf("%d", &r);
    scanf("%d", &c);
    printf("Input Matrix 1");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Input Matrix 2\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &brr[i][j]);
        }
    }
    if (b != r)
    {
        printf("NOT Possible ");
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans[i][j] = 0;
                for (int k = 0; k < b; k++)
                {
                    ans[i][j] += (arr[i][k] * brr[k][j]);
                }
            }
        }
        printf("Answer of Matrix 1*Matrix 2\n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < c; j++)
            {
                printf("%d\t", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}