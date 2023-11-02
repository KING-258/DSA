#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *root = NULL;
void insertNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    struct Node *temp = root;
    while(1)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else if (data > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
        else
        {
            printf("Duplicate data not allowed!\n");
            free(newNode);
            return;
        }
    }
}
void Inorder(struct Node *node)
{
    if (node != NULL)
    {
        Inorder(node->left);
        printf("%d ", node->data);
        Inorder(node->right);
    }
}
int main()
{
    int choice, data;
    do
    {
        printf("\nBinary Tree Menu\n");
        printf("1. Insert a node\n");
        printf("2. Inorder\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertNode(data);
            break;
        case 2:
            printf("Binary Tree (inorder traversal): ");
            Inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);
    return 0;
}