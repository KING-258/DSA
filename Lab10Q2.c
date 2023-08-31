#include<stdio.h>
int fib(int);
int main()
{
	int n;
    printf("Position in fibnoci series \t");
	scanf("%d",&n);
	printf("Element at given position is %d",fib(n)); // Calling function
}
int fib(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1||n==2)
	{
		return 1;
	}
	return fib(n-1)+fib(n-2);
}