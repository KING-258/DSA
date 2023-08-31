#include <stdio.h>
int REV(int n)
{
          int m = n;
          int re;
          re=0;
          while (n!=0)
          {
                    re = re*10 + n%10;
          }
          return re;
}
int main()
{
          int a ;
          int arr[80];
          printf("Total Numbers\t");
          scanf("%d",&a);
          printf("\nInput 5 Digit Number");
          for(int i=0; i<a; i++)
          {
                    scanf("%d",&arr[i]);
          }
          for(int i=0; i<a; i++)
          {
                    int temp=0;
                    int re;
                    temp =arr[i];
                    re = REV(temp);
                    if(re == temp)
                    {
                              printf("%d Opens Locker",re);
                    }
          }
          return 0;
}