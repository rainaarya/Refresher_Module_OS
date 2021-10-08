-------------PREREQUISTES--------------
Use a Linux Environment
Have gcc installed
Have make installed


-------INSTRUCTIONS FOR MAKEFILE AND COMPILATION-------
cd to the directory of Assignment 1 and type 'make' in terminal.
This will compile the C program codes for all questions and generate their respective executables.

To compile and generate executables for specific questions/parts only follow this:
In the terminal, type make, followed by the assignment number, question number and part number(if it exists) with the following syntax: 'make a#q#p#' (where '#' should represent the number)
For example, 'make a1q1' generates the executable for the first question of Assignment 1

To clean/delete all generated executables, type 'make clean' in the terminal.


---------DETAILS FOR QUESTION 1--------

This question has no Subparts. The program takes input via command line arguments.
The C file name for the same is 'a1q1.c' and the executable file name is 'a1q1'

To test the program: The program takes command line arguments as source and destination filenames and copies the source to the destination using 
fread() and fwrite(). Run the program, with source and destination filenames as arguments. After executition, the copied file is then generated in the folder.
For example, './a1q1 hello.bin bye.bin' will copy the contents of file hello.bin (if it exists) to bye.bin. If source file
does not exist, error is printed.

---------DETAILS FOR QUESTION 2--------

???

---------DETAILS FOR QUESTION 3--------

This question has no Subparts.
The C file name for the same is 'a1q3.c' and the executable file name is 'a1q3'

The program asks the user for two variables and swaps them. It then asks the user for two arrays and swaps them.

To test the program: Run a1q3 and enter the value of two variables when promted. After that,
the variable values before and after swapping are printed. Next, enter the size of the arrays you would like to swap,
followed by elements of 1st and 2nd array. After that, the array values before and after swapping are printed.

---------DETAILS FOR QUESTION 4--------

This question has no Subparts. It reverses a string.
The C file name for the same is 'a1q4.c' and the executable file name is 'a1q4'

To test the program: Run a1q4 and enter any string to be reversed (max 100 chars). The output is the string before and after reversal.


---------DETAILS FOR QUESTION 5--------

This question has no Subparts. The program sorts the array and then it performs Binary Search.
The C file name for the same is 'a1q5.c' and the executable file name is 'a1q5'

To test the program: Run a1q5 and enter the size of array, followed by the array elements. Since the question
says to assume 4294967290, 4294967295, 10400 are part of the array, the input entered should contain these values too.

After the program displays the sorted array, enter the element key you wish to search for. In case of success, the 
program outputs that the element is found and the position of element in sorted array is printed. In case of 
faliure, the program prints the message that the key does not exist.



















