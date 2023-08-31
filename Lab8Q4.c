#include<stdio.h>
int CornerSum(int r, int c);
int main()
{
    int R;
    int C;
    printf("Number of Rows");
    scanf("%d",&R);
    printf("Number of Columns");
    scanf("%d",&C);
    int sum= CornerSum(R,C);
    printf("\n");
    printf("Sum is %d",sum);
    return 0;
}

int CornerSum(int r, int c)
{
    int arr[100][100];
    int i;
    int j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    int a;
    a=arr[0][0]+arr[r-1][c-1]+arr[r-1][0]+arr[0][c-1];
    return a;
}