#include <stdio.h>
static int count=0;
void ToH(int d, char rf, char rt, char via){
    if (d == 1)
    {
        printf("%d Disk moves from Rod %c to Rod %c\n", d, rf, rt);
        count++;
        return;
    }
    ToH(d - 1, rf, via, rt);
    printf("%d Disk moves from Rod %c to Rod %c\n", d, rf, rt);
    count++;
    ToH(d - 1, via, rt, rf);
}
int main(){
    int a;
    printf("Number of Disks\t");
    scanf("%d", &a);
    ToH(a, 'A', 'C', 'B');
    printf("\n Moves is %d", count);
    return 0;
}