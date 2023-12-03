#include <stdio.h>
struct Stack
{
    int arr[80];
    int top;
};
void Push(struct Stack *s1, int a)
{
    if (s1->top == 79)
    {
        printf("Stack Overflow");
    }
    else
    {
        s1->arr[s1->top++] = a;
    }
}
void Display(struct Stack s1)
{
    printf("Binary Number : ");
    for (int i = 0; i < s1.top; ++i)
    {
        printf("%d", s1.arr[i]);
    }
}
int main()
{
    int n, rem;
    struct Stack s1;
    s1.top = 0;
    printf("Decimal Number : \t");
    scanf("%d", &n);
    while (n != 0)
    {
        rem = n % 2;
        Push(&s1, rem);
        n = n / 2;
    }
    Display(s1);
    return 0;
}