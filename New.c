#include <stdio.h>
int main()
{
    int i,j,m,flag=0;
    int a[m][m];
    int b[m][m];
    printf("Enter the dimensions of square array: ");
    scanf("%d",&m);
    printf("Enter elements: ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    //transpose
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    //condition check for symmetry
    for(i=0;i<m;i++)
    {
        for(j=0;i<m;i++)
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