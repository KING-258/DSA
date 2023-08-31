#include <stdio.h>
void main()
{
    int max = 100;
    char str[max];
    printf("enter the string  : ");
    scanf("%s",&str);
    int strlen = -1;
    for (int i=0;str[i]!=0;i++)
    {
        strlen++;
    }
    int flag = 0;
    for (int i=0;i<(strlen/2)+1;i++)
    {
        if (str[i]!=str[strlen-i])
        {
            printf("the string is not a palindrome.");
            flag = 1;
            break;
        }
    }
    if (flag==0)
        printf("the string is a palindrome");
}