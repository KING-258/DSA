#include <stdio.h>
#include <string.h>
void Copy(char s[], int a, int b)
{
    char str[80];
    str[a] = s[a];
    if (a == b)
    {
        return;
    }
    Copy(s, a + 1, b);
    puts(str);
}
int main()
{
    char str[80];
    int l;
    printf("Input String 1\t");
    scanf("%s", str);
    l = strlen(str);
    printf("String 1 is %d", l);
    Copy(str, 0, l);
    return 0;
}