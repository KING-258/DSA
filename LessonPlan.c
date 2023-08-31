#include <stdio.h>
int sum(int a,int b);
int main()
{
    int x, y;
    printf ("FirstNumber");
    scanf("%d",&x);
    printf("SecondNumber");
    scanf("%d",&y);

    int s=sum(x, y);
    printf ("%d",s);
    return 0;
}


int sum (int a, int b)
{
    int c=a+b;
    return c;
}