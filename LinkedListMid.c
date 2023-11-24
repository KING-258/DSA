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
    temp->next = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
        t = head;
        while(t->next != NULL){
            t = t->next;
        }
        t->next = temp;
    }
}
int find(int a){
    t = head;
    int flag = 0;
    int l = 1;
    while(t != NULL){
        if(t->data == a){
            flag = 1;
            break;
        }
        l++;
        t = t->next;
    }
    if(flag == 0){
        printf("%d Not Found\n",a);
        return -1;
    }
    else{
        return l;
    }
}
void Replace(int a, int b){
    t = head;
    int flag = 0;
    while(t != NULL){
        if(t->data == a){
            flag = 1;
            t->data = b;
        }
        t = t->next;
    }
    if(flag == 0){
        printf("%d Not Found so cannot be replaced with %d\n",a,b);
    }
    else{
        printf("Operation Executed Successfully Run Display to view Result\n");
    }
}
void DeleteDuplicates(){
    temp = head;
    struct Node *a;
    do{
        t = temp->next;
        while(t != NULL){
            if(t->data == temp->data){
                a = head;
                while(a->data != t->data){
                    a = a->next;
                }
                t = t->next->next;
                temp->next = t;
            }
            else{
                t = t->next;
            }
        }
        temp = temp->next;
    }while(temp->next != NULL);
}
void AddK(int key, int a){
    struct Node *new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = a;
    t = head;
    while(t->data != key && t != NULL){
        t = t->next;
    }
    temp = t->next;
    t->next = new;
    new->next = temp;
    printf("Operation Executed Successfully Run Display to view Result\n");
}
int Remove(){
    int a;
    temp = head;
    head = head->next;
    a = temp->data;
    free(temp);
    return a;
}
void NodeAt(int a){
    t = head;
    for(int i=1; i<a; i++){
        t = t->next;
    }
    printf("Node at %d is %d\n",a,t->data);
}
int length(){
    int size = 1;
    t = head;
    if(head == NULL){
        return --size;
    }
    else{
        while(t->next != NULL){
            size++;
            t = t->next;
        }
        return size;
    }
}
void Display(){
    t = head;
    while(t != NULL){
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
}
int main(){
    int ch;
    do{
        printf("\nMenu\n1.Add()\n2.Remove()\n3.Display()\n4.Length()\n5.ElementAt()\n6.Find()\n7.Replace()\n8.AddAfterValue()\n9.DeleteDuplicates()\n10.Exit()\n");
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
            printf("%d Removed\n",ele);
        }
        else if(ch == 3){
            Display();
        }
        else if(ch == 4){
            int l = length();
            printf("Currently List has %d Nodes\n",l);
        }
        else if(ch == 5){
            int a;
            printf("Input Position of Node ");
            scanf("%d",&a);
            NodeAt(a);
        }
        else if(ch == 6){
            int ele;
            printf("Element to Search : ");
            scanf("%d",&ele);
            int pos = find(ele);
            if(pos != -1){
                printf("Element %d located at %d\n",ele,pos);
            }
            else{
                printf("Element %d not in List\n",ele);
            }
        }
        else if(ch == 7){
            int ele, a;
            printf("Element to be replaced : ");
            scanf("%d",&ele);
            printf("Elemet to replace with : ");
            scanf("%d",&a);
            Replace(ele, a);
        }
        else if(ch == 8){
            int ele, key;
            printf("Element to Add : ");
            scanf("%d",&ele);
            printf("Elemet to Add After : ");
            scanf("%d",&key);
            AddK(key,ele);
        }
        else if(ch == 9){
            DeleteDuplicates();
            printf("If Duplicates were found they are deleted Check by running Display\n");
        }
        else if(ch == 10){
            printf("!!!Exit!!!\n");
        }
        else{
            printf("Retry\n");
        }
    }while(ch != 10);
    return 0;
}