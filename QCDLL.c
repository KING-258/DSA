#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL, *temp, *t;
void Add(int a){
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = a;
    if(head == NULL){
        head = temp;
        head->next = head;
    }
    else{
        t = head;
        while(t->next != head){
            t = t->next;
        }
        t->next = temp;
        temp->prev = t;
        temp->next = head;
    }
}
void Remove(){
    if(head == NULL){
        printf("Nothing in Q\n");
    }
    else if(head->next == head){
        printf("%d was Removed Successfully\n",head->data);
        head = NULL;
    }
    else{
        temp = head;
        t = head;
        while(t->next != head){
            t = t->next;
        }
        head = head->next;
        t->next = head;
        printf("%d was Removed Successfully\n",temp->data);
        free(temp);
    }
}
void Display(){
    temp = head;
    if(head == NULL){
        printf("Nothing in LL");
    }
    else{
        printf("%d ",temp->data);
        while(temp->next != head){
            printf("%d ",temp->next->data);
            temp = temp->next;
        }
        printf("Repeat\n");
    }
}
int main(){
    int ch;
    printf("Menu\n1.Add()\n2.Remove()\n3.Display()\n4.Exit\n");
    do{
        printf("Input Choice : ");
        scanf("%d",&ch);
        if(ch == 1){
            int ele;
            printf("Element to Add : ");
            scanf("%d",&ele);
            Add(ele);
        }
        else if(ch == 2){
            Remove();
        }
        else if(ch == 3){
            Display();
        }
        else if(ch == 4){
            printf("***EXIT***\n");
        }
        else{
            printf("Try Again\n");
        }
    }while(ch != 4);
    return 0;
}