#include <stdio.h>
int main()
{
    int i,j,m,n,flag=1;
    int a[80][80];
    int b[80][80];
    printf("Enter the dimensions of square array: ");
    scanf("%d%d",&m,&n);
    printf("Enter elements: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    //transpose
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    //condition check for symmetry
    for(i=0;i<m;i++)
    {
        for(j=0;i<n;i++)
        {
            if(a[i][j]!= b[j][i])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        printf("The array is symmetric");
    }
    if(flag==1)
    {
        printf("The array is not symmetric");
    }
    return 0;
} 