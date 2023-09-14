#include<stdio.h>
#include<string.h>
char arr[20];
int top = -1;
char r[20];
int topr = -1;
void Push(char a)
{
          top++;
          arr[top] = a;
}
void PushR(char a)
{
          topr++;
          r[topr] = a;
}
int main()
{
          char in[20];
          int l,s;
          printf("Input String ");
          scanf("%s",&in);
          l = strlen(in);
          for(int i=0; i<l; i++)
          {
                    Push(in[i]);
          }
          for(int i=l-1; i>=0; i--)
          {
                    PushR(in[i]);
          }
          s = strcmp(arr, r);
          if (s == 0)
          {
                    printf("Palindrome");
          }
          else{
                    printf("Not a Palindrome");
          }
          return 0;
}