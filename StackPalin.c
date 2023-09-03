#include<stdio.h>
struct Stack
{
          int arr[80];
          int top;
};
void Push(struct Stack *s1, int a)
{
          if(s1 -> top == 79)
          {
                    printf("Stack Overflow");
          }
          else{
                    s1->arr[s1->top++] = a;
          }
}
struct Stack Reverse(struct Stack s1)
{
          struct Stack s2;
          s2.top = s1.top;
          for(int i=s1.top; i>=0; i--)
          {
                    for(int j=0; j<s2.top; j++)
                    {
                              s2.arr[j] = s1.arr[i];
                    }
          }
          return s2;
}
void Display(struct Stack s1)
{
          printf("\nBinary Number\n");
          for(int i=0; i<s1.top; ++i)
          {
                    printf("%d",s1.arr[i]);
          }
}
int main()
{
          int n, rem;
          struct Stack s1;
          struct Stack s2;
          s1.top = 0;
          printf("Decimal Number : \t");
          scanf("%d",&n);
          while(n!=0)
          {
                    rem = n % 2;
                    Push(&s1, rem);
                    n = n / 2;
          }
          Display(s1);
          s2 = Reverse(s1);
          Display(s2);
          return 0;
}