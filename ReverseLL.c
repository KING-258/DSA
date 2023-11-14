#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
struct Node *head = NULL, *t, *temp;
void Push(int a){
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = a;
	if(head == NULL){
		head = temp;
		head->next = NULL;
	}
	else{
		t = head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		t->next = temp;
		temp->next = NULL;
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
	struct Node *curr, *prev, *nextT;
	curr = head;
	prev = NULL;
	nextT = NULL;
	while(curr != NULL){
		nextT = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextT;
	}
	head = prev;
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