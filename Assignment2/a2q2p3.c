#include <stdio.h>
#include <stdlib.h>

struct Node  //stack as a linked list
{
    int val;
    struct Node *next;
};

struct Node *top = NULL; //initially, stack top is NULL

void push(int value)
{
    struct Node *tempNode;  //declare tempNode pointer of type Node
    tempNode = (struct Node *)malloc(sizeof(struct Node));  //allocate memory for the tempNode

    if (top == NULL)      //if the stack is empty
    {
        tempNode->val = value; //assign value in the tempNode
        tempNode->next = NULL; //the next of tempNode is null (since there is only one element in stack)
    }
    else //otherwise
    {
        tempNode->val = value;  //assign value in the tempNode
        tempNode->next = top;   //the next of tempNode is the top node (the previous node below it)
    }
    top = tempNode; //assign the new top node as the tempNode
    printf("\nThe element has been inserted!\n");
}
void pop()
{
    if (top == NULL) //if stack is empty
        printf("\nThe Stack is Empty. Underflow!\n");
    else
    {
        struct Node *temp = top;   
        printf("\nThe element that was deleted is: %d", temp->val); //output node that will be deleted
        top = temp->next;     //change top to next node of temp (popping)
        free(temp);           // free memory of temp node as it is no longer needed
    }
}
void display()
{
    if (top == NULL)  //if stack is empty
        printf("\nThe Stack is Empty\n");
    else
    {
        printf("\nCurrently, the Stack looks like:\n");
        struct Node *temp = top;
        int i = 1;

        while (temp->next != NULL)  // loop till the last element in stack
        {
            if (i == 1)
            {
                printf("%d (TOP)--> ", temp->val);
            }
            else
            {
                printf("%d --> ", temp->val);
            }
            temp = temp->next;     //assign temp to next element in the stack
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
    while (ch == 'y' || ch == 'Y') //menu driven program
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
            push(value); //push the value
            break;
        case 2:
            pop();   //pop from stack
            break;
        case 3:

            display();  //display current stack state
            break;

        default:
            printf("\nInvalid option selected.\n");
        }

        printf("\nDo you want to repeat the Menu? (y/n): ");
        getchar();
        scanf("%c", &ch);
    }
}
