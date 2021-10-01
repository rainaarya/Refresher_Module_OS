#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *tempNode;
    tempNode = (struct Node *)malloc(sizeof(struct Node));

    if (top == NULL)
    {
        tempNode->val = value;
        tempNode->next = NULL;
    }
    else
    {
        tempNode->val = value;
        tempNode->next = top;
    }
    top = tempNode;
    printf("\nThe element has been inserted!\n");
}
void pop()
{
    if (top == NULL)
        printf("\nThe Stack is Empty. Underflow!\n");
    else
    {
        struct Node *temp = top;
        printf("\nThe element that was deleted is: %d", temp->val);
        top = temp->next;
        free(temp);
    }
}
void display()
{
    if (top == NULL)
        printf("\nThe Stack is Empty\n");
    else
    {
        printf("\nCurrently, the Stack looks like:\n");
        struct Node *temp = top;
        int i = 1;

        while (temp->next != NULL)
        {
            if (i == 1)
            {
                printf("%d (TOP)--> ", temp->val);
            }
            else
            {
                printf("%d --> ", temp->val);
            }
            temp = temp->next;
            i++;
        }
        if (i == 1)
            printf("%d (TOP)--> NULL", temp->val);
        else
            printf("%d--> NULL", temp->val);
    }
}

void main()
{
    int userinput;
    char ch = 'y';

    printf("\n\t\tStack using Linked List\n");
    while (ch == 'y' || ch == 'Y')
    {
        printf("\n\t\tSelect from following options\n");
        printf("1. Push\n2. Pop\n3. Display");
        printf("\n\nEnter your choice: ");
        scanf("%d", &userinput);
        switch (userinput)
        {
        case 1:
            printf("Enter the value to insert in stack: ");
            int value;
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
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
