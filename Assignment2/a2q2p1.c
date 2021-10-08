#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
   int rollno;
   char name[50];
   int year_of_join;
   char program[50];

   struct Node *next;
};

struct Node *head = NULL; //head of linked list
struct Node *current = NULL; //last element of linked list

void insert(int rollno, char name[], int year_of_join, char program[])
{

   if (head == NULL) //if there is no element
   {
      head = (struct Node *)malloc(sizeof(struct Node)); //allocate memory to initialise the first node (head)
      head->rollno = rollno;     //Assign the necessary details
      strcpy(head->name, name);
      head->year_of_join = year_of_join;
      strcpy(head->program, program);
      current = head; //make current point to the head (as there is only 1 element currently)
   }
   else
   {
      struct Node *newnode = NULL;  //Declare a newnode of Node type
      newnode = (struct Node *)malloc(sizeof(struct Node));  //Allocate memory for the newnode
      newnode->rollno = rollno;  //Assign the necessary details
      strcpy(newnode->name, name);
      newnode->year_of_join = year_of_join;
      strcpy(newnode->program, program);
      current->next = newnode;  //link the last node of the linked list to this new node
      current = current->next;  //make the new node as the last node of linked list
   }
}

void print(struct Node *temp)
{
   while (temp != NULL)  //loop till temp node is not null
   {
      printf("\nRoll no: %d", temp->rollno);
      printf("\nName: %s", temp->name);
      printf("Year of join: %d", temp->year_of_join);
      printf("\nProgram: %s\n", temp->program);
      temp = temp->next; //go to the next node in the linked list
   }
}

int main()
{
   printf("Please Enter Student Records:\n\n");
   char ch = 'y';
   int i = 1;
   int rollno;          //variable declarations
   char name[50];
   int year_of_join;
   char program[50];
   while (ch == 'y' || ch == 'Y')
   {
      printf("Enter details of student %d\n", i);
      printf("Enter name: ");
      fgets(name, 50, stdin);

      printf("Enter Roll number: ");
      scanf("%d", &rollno);
      printf("Enter Year of joining: ");
      scanf("%d", &year_of_join);
      getchar();
      printf("Enter academic program: ");
      fgets(program, 50, stdin);

      insert(rollno, name, year_of_join, program); //insert the elements in the singly linked list
      i++;

      printf("\nDo you want to enter more records? (y/n): ");
      scanf("%c", &ch);
      getchar();
   }

   printf("\n\t\t All Student details:\n");
   print(head); //print the contents in the linked list
   return 0;
}