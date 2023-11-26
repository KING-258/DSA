#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
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
        temp->next = head;
    }
}
int Remove(){
    temp = head;
    t = head;
    if(head == NULL){
        printf("Try Adding some Elements\n");
        return -1;
    }
    else if(head->next == head){
        int a = head->data;
        head = NULL;
        return a;
    }
    else{
        while(t->next != head){
            t = t->next;
        }
        head = head->next;
        t->next = head;
        int a = temp->data;
        free(temp);
        return a;
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
    do{
        printf("\nMenu\n1.Add()\n2.Remove()\n3.Display()\n4.Exit()\n");
        printf("Input Choice : ");
        scanf("%d",&ch);
        if(ch == 1){
            int ele;
            printf("Element to Add :");
            scanf("%d",&ele);
            Add(ele);
        }
        else if(ch == 2){
            int ele = Remove();
            if(ele ==  -1){
                printf("Empty LL");
            }
            else{
                printf("%d Exits the List\n",ele);
            }
        }
        else if(ch == 3){
            Display();
        }
        else if(ch == 4){
            printf("!!!Exit!!!\n");
        }
        else{
            printf("Retry\n");
        }
    }while(ch != 4);
    return 0;
}