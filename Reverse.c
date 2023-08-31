#include<stdio.h>
int Reverse(int n);
int main()
{
    int a;
    printf("Number to be Reversed");
    scanf("%d",&a);
    int b = Reverse(a);
    printf("Reverse is %d",b);
    return 0;
}

int Reverse(int n)
{
    int rev=0, rem;
    while (n!=0)
    {
        rem= n%10;
        rev= rev*10 + rem;
        n=n/10;
    }
    return rev;
}