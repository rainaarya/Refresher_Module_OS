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

struct Node *head = NULL;
struct Node *tail = NULL;

void insert(int rollno, char name[], int year_of_join, char program[])
{

   if (head == NULL)
   {
      head = (struct Node *)malloc(sizeof(struct Node));
      head->rollno = rollno;
      strcpy(head->name, name);
      head->year_of_join = year_of_join;
      strcpy(head->program, program);
      tail = head;
   }
   else
   {
      struct Node *newnode = NULL;
      newnode = (struct Node *)malloc(sizeof(struct Node));
      newnode->rollno = rollno;
      strcpy(newnode->name, name);
      newnode->year_of_join = year_of_join;
      strcpy(newnode->program, program);
      tail->next = newnode;
      newnode->prev = tail;
      tail = tail->next;
   }
}

void printlist(struct Node *temp)
{
   while (temp != NULL)
   {
      printf("\nRoll no: %d", temp->rollno);
      printf("\nName: %s", temp->name);
      printf("Year of join: %d", temp->year_of_join);
      printf("\nProgram: %s\n", temp->program);
      temp = temp->next;
   }
}


int main()
{
   printf("Please Enter Student Records:\n\n");
   char ch = 'y';
   int i = 1;
   int rollno;
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
   printlist(head);
   
   return 0;
}