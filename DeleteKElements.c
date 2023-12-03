#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int *st;
    int tos;
};
struct Stack push(struct Stack s, int x)
{
    s.tos += 1;
    s.st[s.tos] = x;
    return s;
}
struct Stack del(struct Stack s, int ind)
{
    int i;
    for (i = ind; i < s.tos; i++)
    {
        s.st[i] = s.st[i + 1];
    }
    s.tos -= 1;
    return s;
}
int main()
{
    struct Stack s;
    int n, i, k;
    printf("Enter number of elements ");
    scanf("%d", &n);
    s.st = (int *)malloc(n * sizeof(int));
    printf("Input Elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s.st[i]);
    }
    s.tos = n - 1;
    printf("Input K ");
    scanf("%d", &k);
    while (k > 0)
    {
        for (i = 0; i <= s.tos - 1; i++)
        {
            if (s.st[i] < s.st[i + 1])
            {
                s = del(s, i);
                k -= 1;
                break;
            }
        }
    }
    printf("The final array is:\n");
    for (i = 0; i <= s.tos; i++)
    {
        printf("%d ", s.st[i]);
    }
    return 0;
}