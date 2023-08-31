#include<stdio.h>
int fact(int a);
int main()
{
    int x;
    int y;
    printf("N Number\t");
    scanf("%d",&x);
    printf("R Number\t");
    scanf("%d",&y);
    int z=x-y;
    int n=fact(x);
    int r=fact(y);
    int m=fact(z);
    int a=n/(r*m);
    printf("NCR is \n %d",a);
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