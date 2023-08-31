#include<stdio.h>
void ToH(int d, char rf, char rt, char via)
{
          if(d == 1)
          {
                    printf("%d Disk moves from Rod %c to Rod %c\n",d,rf,rt);
                    return;
          }
          ToH(d-1, rf, via, rt);
          printf("%d Disk moves from Rod %c to Rod %c\n",d,rf,rt);
          ToH(d-1, via, rt, rf);
}
int main()
{
          int a;
          printf("Number of Disks\t");
          scanf("%d",&a);
          ToH(a, 'A', 'C', 'B');
          return 0;
}