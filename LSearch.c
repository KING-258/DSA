#include<stdio.h>
void LSearch(int arr[80], int a, int b)
{
          for(int i=0; i<a; i++)
          {
                    if(arr[i]==b)
                    {
                              printf("Element found at %d",i+1);
                    }
          }
}
int main()
{
          int a;
          int arr[80];
          int s;
          printf("Input Array Size\t");
          scanf("%d",&a);
          printf("Input Elements \t");
          for(int i=0; i<a; i++)
          {
                    scanf("%d",&arr[i]);
          }
          printf("Element to be searched\t");
          scanf("%d",&s);
          LSearch(arr, a, s);
          return 0;
}