#include<stdio.h>
int main()
{
    int r;
    int c;
    int a[80][80];
    int l = 0;
    printf("Number of Rows\t");
    scanf("%d",&r);
    printf("Number of Columns\t");
    scanf("%d",&c);
    printf("Input Matrix");
    printf("\n");
    for(int i=0; i<r; i++)
    {
          for(int j=0; j<c; j++)
          {
          scanf("%d",&a[i][j]);
          }
    }
    for(int i=0; i<r; i++)
    {
          for(int j=0; j<c; j++)
          {
                    if(l<a[i][j])
                    {
                              l = a[i][j];
                    }
          }
    }
    for(int i=0; i<r; i++)
    {
          for(int j=0; j<c; j++)
          {
                    if(a[i][j] == l)
                    {
                              printf("%d is Largest and is at %d , %d",l,i+1,j+1);
                    }
          }
    }
    return 0;
}