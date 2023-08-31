#include<stdio.h>
int fact(int a);
int main()
{
    int x;
    printf("Number");
    scanf("%d",&x);
    int s= fact(x);
    printf("%d",s);
    return 0;
}

int fact(int a)
{
    if(a==1)
    {
        return 1;

    }
    int factaM1= fact(a-1);
    int facta= factaM1*a;
    return facta;
}