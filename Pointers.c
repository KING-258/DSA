#include<stdio.h>
void Newa(int *a )
{
          *a = 25;
}
void _Newa(int a)
{
          a = 50;
}
int main()
{
          int a = 5;
          printf("%d\t",a);
          Newa(&a);//Call by reference
          printf("%d\n",a );
          printf("%p\n",&a);
          _Newa(a);//Call by Value 
          printf("%d",a);//Scope of variable is local and is valid only inside _Newa
          return 0;
}