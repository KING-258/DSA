#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL, *temp, *t;
void Push(int a){
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = a;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        head->prev = NULL;
    }
    else{
        t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
        temp->prev = t;
    }
}
void Display(){
	if (head == NULL)
	{
		printf("List is Empty\n");
	}
	else{
		t = head;
		while (t != NULL)
		{
			printf("|%d|-->",t->data);
			t = t->next;
		}
		printf("NULL\n");
	}
}
void Reverse(){
    t = head;
    temp = NULL;
    while(t != NULL){
        temp = t->prev;
        t->prev = t->next;
        t->next = temp;
        t = t->prev;
    }
    head = temp->prev;
}
int main(){
    int a;
	printf("Input Data (Input -1 to exit)");
	do{
		scanf("%d",&a);
		if(a == -1){
			printf("!!!Exit!!!\n");
		}
		else{
			Push(a);
		}
	}while(a != -1);
	printf("LL : \n");
	Display();
	Reverse();
	printf("Reverse LL : \n");
	Display();
	return 0;
}