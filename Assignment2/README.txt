-------------PREREQUISTES--------------
Use a Linux Environment
Have gcc installed
Have make installed


-------INSTRUCTIONS FOR MAKEFILE AND COMPILATION-------
cd to the directory of Assignment 2 and type 'make' in terminal.
This will compile the C program codes for all questions and generate their respective executables.

To compile and generate executables for specific questions/parts only follow this:
In the terminal, type make, followed by the assignment number, question number and part number(if it exists) with the following syntax: 'make a#q#p#' (where '#' should represent the number)
For example, 'make a2q2p1' generates the executable for the 1st part of the 2nd question of Assignment 2
and 'make a2q1' generates the executable for the first question of Assignment 2 

To clean/delete all generated executables, type 'make clean' in the terminal.


---------DETAILS FOR QUESTION 1--------

This question has 2 Subparts. I have combined the functionality of both subparts into a single C program.
The C file name for the same is 'a2q1.c' and the executable file name is 'a2q1'

The program first generates the matrix using the appropriate functions (subpart 1). Then it asks the user 
about the row number where he/she wants the column size to change and asks for the new column size (subpart 2).

To test the program: Run the program and see the generated matrix. After that, enter the desired row number
whose columns you want to change. Then type the new column size you want and you will see the changes reflected in the matrix as output.

---------DETAILS FOR QUESTION 2--------

This question has 4 Subparts. First subpart is the C program for singly linked list implementation. Second subpart
is the doubly linked list implementation. Third subpart is stack implementation and fourth subpart is queue implementation.

C file names: a2q2p1.c, a2q2p2.c, a2q2p3.c, a2q2p4.c
Executable names: a2q2p1, a2q2p2, a2q2p3, a2q2p4

To test the programs: Run a2q2p1 and enter the student details as promted. Continue doing it if you wish to add
more nodes in the list. Once you are done filling, the contents in each node of linked list gets printed.
Follow the same prodecure to test a2q2p2 as well. 

To test part 3(stack code), run a2q2p3 and enter your choice of operaton in the menu (push, pop or display). push() would
push an element entered by user into the stack top, pop() would delete the top element and display() would show the current state of the stack.
To repeat the menu after the operaton, enter 'y' else enter 'n' if you would like to stop.

To test part 4(queue code), run a2q2p4 and enter your choice of operaton in the menu (insert, delete or display). insert() would
insert an element entered by user into the queue rear, delete() would delete the queue element from front, display() would show the current state of the queue.
To repeat the menu after the operaton, enter 'y' else enter 'n' if you would like to stop.

---------DETAILS FOR QUESTION 3--------

This question has no Subparts.
The C file name for the same is 'a2q3.c' and the executable file name is 'a2q3'

The program asks the user for the arguments and operaton and calls the appropriate function (whose location is stored in the pointer array).

To test the program: Run a2q3 and enter the value of two arguments 'a' and 'b' when promted. After that,
provide your choice of function by entering the appropriate digit (0-4). The output is then displayed.

---------DETAILS FOR QUESTION 4--------

CANCELLED

---------DETAILS FOR QUESTION 5--------

This question has no Subparts.
The C file name for the same is 'a2q5.c' and the executable file name is 'a2q5'

The program asks the user which sort function is to be performed and sorts the array inputted by the user using the
specified sorting function.

To test the program: Run a2q5 and enter the array elements when promted. After that,
provide your choice of sort function by entering 'b' for Bubble Sort or 's' for Selection Sort.
The sorted array is then displayed as output.




















