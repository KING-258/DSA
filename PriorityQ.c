#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data[20];
    int priority;
};
struct Node P[80];
int index = 0;
int out = 0;
void Add(struct Node s){
    if(index-out >= 80){
        printf("!!!Queue is Full!!!\n");
    }
    else{
        P[index] = s;
        index++;
    }
}
void Sort(){
    for(int i=out; i<=index; i++){
        for(int j=i+1; j<=index; j++){
            if(P[i].priority<P[j].priority){
                struct Node q = P[j];
                P[j] = P[i];
                P[i] = q;
            }
        }
    }
}
struct Node Remove(){
    if(out == index){
        struct Node v;
        v.priority = -1;
        return v;   
    }
    else{
        struct Node q = P[out];
        out++;
        return q; 
    }
}
void Display(){
    if(out == index){
        printf("Nothing in Queue\n");
    }
    else{
        printf("Queue & Priority : \n");
        int j = 0;
        for(int i=out; i<index; i++){
            printf("%d.%s & %d\n",(j+1),P[i].data,P[i].priority);
            j++;
        }
    }
    printf("\n");
}
int getHighestPriority(){
    int pr = 0;
    for(int i=out; i<index; i++){
        if(P[i].priority>pr){
            pr = P[i].priority;
        }
    }
    return pr;
}
void DeleteHighestPriority(){
    int s = getHighestPriority();
    for(int i=out; i<index; i++){
        if(P[i].priority == s){
            for(int j=i; j<=index-1; j++){
                P[j] = P[j+1];
            }
            index--;
        }
    }
    printf("Changes were made Successfully\n");
}
int isBetween(int a){
    int flag = 0;
    if(a>0 && a<11){
        flag = 1;
    }
    return flag;
}
int main(){
    int ch;
    printf("Menu\n1.Add()\n2.Remove\n3.Sort()\n4.Display()\n5.getHighestPriority()\n6.DeleteHighestPriority()\n7.Exit()\n");
    do{
        printf("Input Choice : ");
        scanf("%d",&ch);
        if(ch == 1){
            int a = 0;
            struct Node o;
            printf("Name of Vehicle : ");
            scanf("%s",&o.data);
            printf("Priority of %s : ",o.data);
            scanf("%d",&a);
            if(isBetween(a) == 0){
                do{
                    printf("Priority must be between 1 to 10\n");
                    printf("Try Again Priority of %s : ",o.data);
                    scanf("%d",&a);
                }while(isBetween(a) != 1);
            }
            o.priority = a;
            Add(o);
        }
        else if(ch == 2){
            struct Node o = Remove();
            if(o.priority == -1){
                printf("Nothing in Queue\n");
            }
            else{
                printf("%s with Priority %d was Removed\n",o.data,o.priority);
            }
        }
        else if(ch == 3){
            Sort();
            printf("Queue Sorted in Descending Order\n");
        }
        else if(ch == 4){
            Display();
        }
        else if(ch == 5){
            printf("%d is Highest Priority\n",getHighestPriority());
        }
        else if(ch == 6){
            DeleteHighestPriority();
        }
        else if(ch == 7){
            printf("***EXIT***\n");
        }
        else{
            printf("Try Again\n");
        }
    }while(ch != 7);
    return 0;
}