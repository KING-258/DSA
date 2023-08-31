#include <stdio.h>  
#include <string.h>
void revstr(char *str,char *str1, int a, int b)  
{
    int s=1;
    if (a==b)
    {

        printf (" \n Before reversing the string: %s \n", str);
        printf("\nAfter Reversing the String: %s \n",str1);
        s = strcmp(str, str1);
        if(s==0)
        {
            printf("Palindrome");
        }
        else
        {
            printf("Not a Palindrome");
        }
        return;
    }
    str1[a] = str[b-a-1];
    a++;
    revstr(str, str1, a, b);
}  
      
    int main()  
    {  
        char str[80];
        char s[80];
        int a = 1;
        printf (" Enter the string: ");  
        gets(str);
        revstr(str, s, 0, strlen(str));
        return 0;
    }  