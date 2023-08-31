#include<stdio.h>
int main()
{
    int max = 100;
    char str[max];
    printf("enter the string : ");
    gets(str);
    int wordcount = 0;
    for (int i=0;str[i]!='\0';i++)
    {
        if (str[i]==' '&&str[i+1]!=' ')
        {
            wordcount+=1;
        }
    }
    printf("%d", wordcount+1);
    return 0;
}