-------------PREREQUISTES--------------
Use a Linux Environment
Have gcc installed
Have make installed


-------INSTRUCTIONS FOR MAKEFILE AND COMPILATION-------
cd to the directory of Assignment 3 and type 'make' in terminal.
This will compile the C program codes for all questions and generate their respective executables.

To compile and generate executables for specific questions/parts only follow this:
In the terminal, type make, followed by the assignment number, question number and part number(if it exists) with the following syntax: 'make a#q#p#' (where '#' should represent the number)
For example, 'make a3q3p1' generates the executable for the 1st part of the 3rd question of Assignment 3
and 'make a3q4' generates the executable for the fourth question of Assignment 3

To clean/delete all generated executables, type 'make clean' in the terminal.


---------DETAILS FOR QUESTION 1--------

This question is a shell script and can be run by typing ./a3q1.sh in the bash terminal. It generates the calender of the month in the date.
First, give it permission to execute by running 'chmod +x a3q1.sh'

To test this program, run the shell script by providing three command line arguments representing the date in the form 'dd mm yyyy'.
For example, to run the script with the date 25/10/2004, type: ./a3q1.sh 25 10 2004

The output is the calender of the month and year if the date is valid. If date is invalid, error is printed.

---------DETAILS FOR QUESTION 2--------

This question is a shell script and can be run by typing ./a3q2.sh in the bash terminal.
First, give it permission to execute by running 'chmod +x a3q2.sh'

To test this program, run the shell script by providing the first argument as the name of the arithmetic operation, followed by
any number of subsequent arguments to represent the operands.
For example the command './a3q2.sh sub 9 2 3' would perform 9-2-3 = 4.

The output is the result of the corresponding arithmetic operation on the operands.

---------DETAILS FOR QUESTION 3--------

This question has two  Subparts.
The first subpart performs insertion and deletion in a BST. The second subpart implements a height balanced BST.

C file names: a3q3p1.c, a3q3p2.c
Executable names: a3q3p1, a3q3p2

To test the programs: To test part 1, run a3q3p1 and enter your choice for performing insertion/deletion/display. For insertion, 
enter the value you want to insert in BST. For deletion, enter the value you want to delete from BST. Display shows the
current state of BST by printing the inorder traversal of the BST.

To test part 2 (height balanced BST), run a3q3p2 and do the same as mentioned above for BST. Here, Display shows the
current state of Height Balanced BST by printing the preorder traversal of the BST.

---------DETAILS FOR QUESTION 4--------

This question has no Subparts.
The C file name for the same is 'a3q4.c' and the executable file name is 'a3q4'

The program asks the user which sort function is to be performed and sorts the array inputted by the user using the
specified sorting function.

To test the program: Run a3q4 and enter the array elements when promted. After that,
provide your choice of sort function by entering 'b' for Bubble Sort or 's' for Selection Sort.
The sorted array is then displayed as output.















