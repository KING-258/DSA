#include<stdio.h>
struct Stack
{
          char arr[80];
          int top;
};
void Push(struct Stack *s1, char a)
{
          if(s1 -> top == 79)
          {
                    printf("Stack Overflow");
          }
          else{
                    s1->arr[s1->top++] = a;
                    printf("%c is pushed into stack",a);
          }
}
void Pop(struct Stack *s1)
{
          if(s1 -> top == -1)
          {
                    printf("Stack Underflow");
          }
          else{
                    char a = s1->arr[s1->top];
                    s1->arr[s1->top--];
                    printf("Popped top");;
          }
}
void Display(struct Stack s1)
{
          printf("\nStack Elements\n");
          for(int i=0; i<s1.top; ++i)
          {
                    printf("%c\t",s1.arr[i]);
          }
}
int main()
{
          struct Stack s1;
          s1.top = 0;
          int n, option;
          char value;
          printf("Menu\n");
          printf("1. Push()\n");
          printf("2. Pop()\n");
          printf("3. Display()\n");
          printf("4. Exit()\n");
          printf("Input Number of Elements for Stack\t");
          scanf("%d",&n);
          for(int i=0; i<n; i++)
          {
                    printf("\nInput Choice\t");
                    scanf("%d",&option);
                    if(option == 1)
                    {
                              printf("Element to be pushed\t");
                              scanf(" %c",&value);
                              Push(&s1, value);
                    }
                    else if (option == 2)
                    {
                              Pop(&s1);
                    }
                    else if(option == 3)
                    {
                              Display(s1);
                    }
                    else if(option == 4)
                    {
                              printf("Exit");
                              break;
                    }
                    else
                    {
                              printf("Not a Valid Response");
                    }
          }
          Display(s1);
          return 0;
}