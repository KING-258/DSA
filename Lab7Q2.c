#include<stdio.h>
int main()
{
    int max = 100;
    char str[max];
    printf("enter the string :");
    scanf("%s",&str);
    for (int i=0;str[i]!='\0';i++)
    {
        if (str[i]>=65&&str[i]<=90)
            str[i]+=32;
        else if (str[i]>=97&&str[i]<=122)
            str[i]-=32;
    }
    printf("%s",str);
    return 0;
}