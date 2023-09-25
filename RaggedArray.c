#include<stdio.h>
#include<stdlib.h>
int **arr;
int main()
{
          int r;
          int c[80];
          printf("Number of Rows ");
          scanf("%d",&r);
          arr = (int**)malloc(r * sizeof(int));
          for (int i = 0; i < r; i++)
          {
                    printf("Number of Columns for %d Row ",(i+1)); 
                    scanf("%d",&c[i]);
                    arr[i] = (int*)malloc(c[i] * sizeof(int));
          }
          printf("Input Elements of the Array\n");
          for(int i=0; i<r;i++)
          {
                    for(int j=0; j<c[i]; j++)
                    {
                              printf("Row->%d & Col->%d ",(i+1),(j+1));
                              scanf("%d",&arr[i][j]);
                    }
          }
          printf("Displaying Matrix\n");
          for(int i=0; i<r; i++)
          {
                    for(int j=0; j<c[i]; j++)
                    {
                              printf("%d  ",arr[i][j]);
                    }
                    printf("\n");
          }
          return 0;
}