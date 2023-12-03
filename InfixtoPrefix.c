#include <stdio.h>
#include <string.h>
char opr[80];
int topopr = -1;
char r[80];
int topr = -1;
void PushOPR(char a)
{
    if (topopr == 79)
    {
        printf("Operand Limit Reached");
    }
    else
    {
        topopr++;
        opr[topopr] = a;
    }
}
char PopOPR()
{
    char ch;
    if (topopr == -1)
    {
        printf("No Operand");
        return -1;
    }
    else
    {
        ch = opr[topopr];
        topopr--;
        return ch;
    }
}
void PushR(char b)
{
    if (topr == 79)
    {
        printf("Operand Limit Reached");
    }
    else
    {
        topr++;
        r[topr] = b;
    }
}
void DisplayR()
{
    for (int i = 0; i <= topr; i++)
    {
        printf("%c", r[i]);
    }
}
char Current()
{
    if (topopr != -1)
    {
        char ch;
        ch = opr[topopr];
        return ch;
    }
}
int Priority(char ch)
{
    if (ch == '^')
    {
        return 4;
    }
    else if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
int main()
{
    char in[20];
    char a;
    printf("Input Infix Expression\n");
    scanf("%s", &in);
    for (int i = strlen(in) - 1; i >= 0; i--)
    {
        a = in[i];
        if (a == ')')
        {
            PushOPR(a);
        }
        else if (a == '(')
        {
            while (Current() != ')')
            {
                char s = PopOPR();
                PushR(s);
            }
            PopOPR();
        }
        else if (a == '^' || a == '*' || a == '/' || a == '+' || a == '-')
        {
            while (Priority(Current()) > Priority(a) && topopr != -1)
            {
                char m = PopOPR();
                PushR(m);
            }
            PushOPR(a);
        }
        else
        {
            PushR(a);
        }
    }
    if (topopr != -1)
    {
        while (topopr != -1)
        {
            char d = PopOPR();
            PushR(d);
        }
    }
    printf("\nPrefix Expression\n");
    for (int i = strlen(r) - 1; i >= 0; i--)
    {
        printf("%c", r[i]);
    }
    return 0;
}