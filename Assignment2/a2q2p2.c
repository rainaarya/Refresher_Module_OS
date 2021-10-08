#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
   int rollno;
   char name[50];
   int year_of_join;
   char program[50];

   struct Node *next; // Pointer to next node
   struct Node *prev; // Pointer to previous node
};

struct Node *head = NULL; //head of doubly linked list
struct Node *tail = NULL; //tail of doubly linked list

void insert(int rollno, char name[], int year_of_join, char program[])
{

   if (head == NULL)
   {
      head = (struct Node *)malloc(sizeof(struct Node)); //allocate memory to initialise the first node (head)
      head->rollno = rollno;    //Assign the necessary details
      strcpy(head->name, name);
      head->year_of_join = year_of_join;
      strcpy(head->program, program);
      tail = head;  //make tail same as the head (as there is only 1 element currently)
   }
   else
   {
      struct Node *newnode = NULL;   //Declare a newnode of Node type
      newnode = (struct Node *)malloc(sizeof(struct Node));   //Allocate memory for the newnode
      newnode->rollno = rollno;  //Assign the necessary details
      strcpy(newnode->name, name);
      newnode->year_of_join = year_of_join;
      strcpy(newnode->program, program);
      tail->next = newnode;   //link the next of tail node to this new node
      newnode->prev = tail;   //link the previous of newnode to current tail node
      tail = tail->next;      //update the tail node to the newly inserted node
   }
}

void printlist(struct Node *temp)
{
   while (temp != NULL)   //loop till temp node is not null
   {
      printf("\nRoll no: %d", temp->rollno);
      printf("\nName: %s", temp->name);
      printf("Year of join: %d", temp->year_of_join);
      printf("\nProgram: %s\n", temp->program);
      temp = temp->next;   //go to the next node in the linked list
   }
}


int main()
{
   printf("Please Enter Student Records:\n\n");
   char ch = 'y';
   int i = 1;
   int rollno;       //variable declarations
   char name[50];
   int year_of_join;
   char program[50];
   while (ch == 'y' || ch == 'Y')
   {
      printf("Enter details of student: %d\n", i);
      printf("Enter name: ");
      fgets(name,50,stdin);

      printf("Enter Roll number: ");
      scanf("%d", &rollno);
      printf("Enter Year of joining: ");
      scanf("%d", &year_of_join);
      getchar();
      printf("Enter academic program: ");
      fgets(program,50,stdin);

      insert(rollno, name, year_of_join, program);
      i++;

      printf("\nDo you want to enter more records? (y/n): ");
      scanf("%c", &ch);
      getchar();
   }

   printf("\n\t\t All Student details:\n");
   printlist(head);     //print the contents in the doubly linked list
   
   return 0;
}