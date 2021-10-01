#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nElement has been inserted in Queue\n");
}
void delete ()
{
    if (front == NULL)
        printf("\nQueue is Empty! Underflow!\n");
    else
    {
        struct Node *temp = front;
        front = front->next;
        printf("\nElement Deleted is: %d\n", temp->val);
        free(temp);
    }
}
void display()
{
    if (front == NULL)
        printf("\nQueue is Empty!\n");
    else
    {
        printf("\nCurrently, the Queue looks like:\n");
        struct Node *temp = front;
        while (temp->next != NULL)
        {
            printf("%d --> ", temp->val);
            temp = temp->next;
        }
        printf("%d --> NULL\n", temp->val);
    }
}

void main()
{
    int userinput, value;
    char ch = 'y';

    printf("\n\t\tQueue Implementation using Linked List\n");
    while (ch == 'y' || ch == 'Y')
    {
        printf("\n\t\tSelect from following options\n");
        printf("1. Insert\n2. Delete\n3. Display");
        printf("\n\nEnter your choice: ");
        scanf("%d", &userinput);
        switch (userinput)
        {
        case 1:
            printf("Enter the value to insert in queue: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        
        default:
            printf("\nInvalid option selected.\n");
        }

        printf("\nDo you want to repeat the Menu? (y/n): ");
        getchar();
        scanf("%c", &ch);
    }
}
