#include<stdio.h>
void Prime(int arr[], int l);
int main()
{
    int a;
    int b;
    printf("Lower Limit");
    scanf("%d",&a);
    printf("Upper Limit");
    scanf("%d",&b);
    int arr[100];
    int c;
    c=b-a+1;
    for(int i=0; i<c; i++)
    {
        arr[i]=a+i;
    }
    for(int i=0; i<c; i++)
    {
        printf("%d\t",arr[i]);
    }
    Prime(arr, c);
    return 0;
}
void Prime(int arr[], int l)
{
    int i;
    int j;
    int flag;
    for(i=0; i<l; i++)
    {
        flag=0;
        for(j=2; j <= (arr[i]/2); j++)
        {
            if(arr[i]%j==0)
            {
                flag=1;
                break;
            }
        }
        if(arr[i]==1)
        {
            flag=1;
        }
        if(flag==0)
        {
            printf("%d is prime\n",arr[i]);
        }
    }
}