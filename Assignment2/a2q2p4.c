#include <stdio.h>
#include <stdlib.h>

struct Node //Queue as a linked list
{
    int val;
    struct Node *next;
};

struct Node *front = NULL; //initially, queue front is NULL
struct Node *rear = NULL;  //initially, queue rear is NULL

void insert(int value)
{
    struct Node *newNode;                                 //declare newNode pointer of type Node
    newNode = (struct Node *)malloc(sizeof(struct Node)); //allocate memory to it
    newNode->val = value;                                 //fill value
    newNode->next = NULL;
    if (front == NULL) //if queue was empty initially
    {
        front = newNode; //assign both front and rear to newNode
        rear = newNode;
    }
    else
    {
        rear->next = newNode; //otherwise, link the next of rear to newNode
        rear = newNode;       //and update the queue rear as the newNode
    }
    printf("\nElement has been inserted in Queue\n");
}
void delete ()
{
    if (front == NULL) //if queue is empty
        printf("\nQueue is Empty! Underflow!\n");
    else
    {
        struct Node *temp = front;
        front = front->next;                             //delete from front by changing queue front to front->next
        printf("\nElement Deleted is: %d\n", temp->val); //output node that is deleted
        free(temp);                                      //free memory of temp as it is no longer needed
    }
}
void display()
{
    if (front == NULL) //if queue is empty
        printf("\nQueue is Empty!\n");
    else
    {
        printf("\nCurrently, the Queue looks like:\n");
        struct Node *temp = front;
        while (temp->next != NULL) // loop till the last element in queue
        {
            printf("%d --> ", temp->val);
            temp = temp->next; //assign temp to next element in the queue
        }
        printf("%d --> NULL\n", temp->val);
    }
}

void main()
{
    int userinput, value;
    char ch = 'y';

    printf("\n\t\tQueue Implementation using Linked List\n");
    while (ch == 'y' || ch == 'Y') //menu driven program
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
            insert(value);  //insert the value in queue
            break;
        case 2:
            delete(); //delete from front in queue
            break;
        case 3:
            display(); //display current queue state
            break;

        default:
            printf("\nInvalid option selected.\n");
        }

        printf("\nDo you want to repeat the Menu? (y/n): ");
        getchar();
        scanf("%c", &ch);
    }
}
