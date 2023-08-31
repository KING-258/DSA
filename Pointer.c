#include<stdio.h>
#include<string.h>
int main()
{
    int a;
    printf("Number");
    scanf("%d",&a);
    int *ptr =&a;//Location of a
    int b = *ptr;//Location at *ptr which is also a
    printf("%d",b);//value of a
    printf("\n%d",ptr);//location of a Address
    printf("\n %d",*ptr);//value at address stored in ptr
    printf("\n %d",&b);//location of b Address
    return 0;
}