#include<stdio.h>
#include<string.h>
int main()
{
    const int a=100;
    char str[a];
    printf("Input String");
    scanf("%s",&str);
    printf("\n String is %s",str);
    return 0;
}