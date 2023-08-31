#include<stdio.h>
#include<string.h>
void Palindrome(char str[], int a);
int main()
{
    char s[100];
    printf("Input");
    gets(s);
    int l=strlen(s);
    Palindrome(s, l);
    return 0;
}
void Palindrome(char str[], int a)
{
    int flag=1;
    for(int i=0; i<a; i++)
    {
        if(str[i]!=str[a-i-1])
        {
            flag=0;
            break;
        }
        else if (str[i]==str[a-i-1])
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("Palindrome");
    }
    else{
        printf("Not a Palindrome");
    }
}