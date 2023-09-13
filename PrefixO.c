#include <stdio.h>
#include <string.h>
int s[50];
int top = 0;
void push(int ch)
{
	top++;
	s[top] = ch;
}
int pop()
{
	int ch;
	ch = s[top];
	top--;
	return (ch);
}
int main()
{
	int a, b, c, i;
	char exp[50];
	printf("Input Expression\t");
	scanf("%s",&exp);
	for (i = strlen(exp) - 1; i >= 0; i--)
	{
		if (exp[i] == '+')
		{
			a = pop();
			b = pop();
			c = b + a;
			push(c);
		}
		else if (exp[i] == '-')
		{
			b = pop();
			a = pop();
			c = b - a;
			push(c);
		}
		else if (exp[i] == '*')
		{
			a = pop();
			b = pop();
			c = b * a;
			push(c);
		}
		else if (exp[i] == '/')
		{
			a = pop();
			b = pop();
			c = b / a;
			push(c);
		}
		else
		{
			push(exp[i] - 48);
		}
	}
	printf("\nFinal ans = %d", s[top]);
	return 0;
}