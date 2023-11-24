#include<stdio.h>
#include<stdlib.h>
struct Person{
    char name[20];
    int age;
};
struct Node{
    struct Person p;
    struct Node *next;
};
struct Node *first = NULL, *temp, *t;
void Add(struct Person p1){
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->p = p1;
    temp->next = NULL;
    if(first == NULL){
        first = temp;
    }
    else{
        t = first;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
    }
}
struct Person Remove(){
    struct Person p1 = first->p;
    temp = first;
    first = first->next;
    free(temp);
    return p1;
}
void Display(){
    t = first;
    while(t != NULL){
        printf("Person : %s(%d)",t->p.name, t->p.age);
        t = t->next;
    }
    printf("\n");
}
int main(){
    int ch;
    printf("Menu\n1.EnterTheQ\n2.ExitTheQ\n3.DisplayTheQ()\n4.Exit()");
    do{
        printf("Input Choice : ");
        scanf("%d",&ch);
        if(ch == 1){
            struct Person p;
            printf("Input Details for the Person\nName : ");
            scanf("%s",&p.name);
            printf("Age : ");
            scanf("%d",&p.age);
            Add(p);
        }
        else if(ch == 2){
            struct Person p = Remove();
            printf("Person\nName : %s\nAge : %d\nwas removed from the Q\n",p.name,p.age);
        }
        else if(ch == 3){
            printf("Party Queue :\n");
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