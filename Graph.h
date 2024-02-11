struct Node{
    int val;
    int weight;
    struct Node *next;
};
void Add(struct Node *head, int a, int b){
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->val = a;
    temp->weight = b;
    temp->next = NULL;
    struct Node *t;
    t = head;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = temp;
}
void Print(struct Node *head){
    struct Node *temp;
    temp = head;
    printf("%d->",temp->val);
    temp = temp->next;
    while(temp != NULL){
        printf(" |%d : %d|",temp->val,temp->weight);
        temp = temp->next;
    }
    printf("\n");
}
struct Graph{
    char name[10];
    struct Node *list;
};