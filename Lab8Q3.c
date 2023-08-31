#include<stdio.h>
char IsPalin(char arr[100]);
int main()
{
    char string[100];
    printf("String");
    scanf("%s",string);
    IsPalin(string[100]);
    int a= IsPalin(string[100]);
    if(a==0)
    {
        printf("Palindrome");
    }
    else(a==1)
    {
        printf("Not a Palindrome");
    }
    return 0;
}

char IsPalin(char arr[100])
{
   int strlen = -1;
    for (int i=0;arr[i]!=0;i++)
    {
        strlen++;
    }
    int flag = 0;
    for (int i=0;i<(strlen/2)+1;i++)
    {
        if (arr[i]!=arr[strlen-i])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}