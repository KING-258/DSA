#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    int cc, dc;
    cc=0;
    dc=0;
    int ds;
    ds=0;
    int d;
    printf("Input String");
    gets(s);
    int l=strlen(s);
    for(int i=0; i<=l; i++)
    {
        if(s[i]>=48 && s[i]<=57)
        {
            d=s[i]-48;
            ds=ds+d;
            dc++;
        }
        else
        {
            cc++;
        }
    }
    printf("Sum of digits is %d\t Number of Digits is %d\t CharacterCount is %d\t",ds ,dc ,cc-1);
    return 0;
}