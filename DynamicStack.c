#include<stdio.h>
#include<stdlib.h>
int *s;
int size = 0;
int tos = -1;
void Initialise(){
    printf("Primary Size Of Stack : ");
    scanf("%d",&size);
    s = (int *) malloc(size*sizeof(int));
}
void Push(int a){
    if(tos == size-1){
        size++;
        s = (int *) realloc(s, size*sizeof(int));
        s[++tos] = a;
    }
    else{
        s[++tos] = a;
    }
}
void Display(){
    for(int i=0; i<=tos; i++){
        printf("%d ",s[i]);
    }
    printf("\n");
}
int Pop(){
    int a = s[tos];
    tos--;
    return a;
}
int main(){
    int ch;
    Initialise();
    printf("Menu\n");
    printf("1. Push()\n");
    printf("2. Pop()\n");
    printf("3. Display()\n");
    printf("4. Exit()\n");
    do{
        printf("Input Choice : ");
        scanf("%d",&ch);
        if(ch == 1){
            int a;
            printf("Element to Push : ");
            scanf("%d",&a);
            Push(a);
        }
        else if(ch == 2){
            int a = Pop();
            printf("%d Popped from Stack\n",a);
        }
        else if(ch == 3){
            printf("Stack Right Now \n");
            Display();
        }
        else if(ch == 4){
            printf("!!!Exit!!!\n");
        }
        else{
            printf("Try Again\n");
        }
    }while(ch != 4);
    return 0;
}