#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_matrix(int *a[], int size[])
{

    for (int i = 0; i < 6; ++i) //6 rows, so we loop through each row
    {
        a[i] = (int *)malloc(size[i] * sizeof(int)); //at the index i of the pointer array, allocate another int array of size size[i]
        for (int j = 0; j < size[i]; ++j) //loop through the columns of the row i
        {
            a[i][j] = (rand() % (9 - 2 + 1)) + 2; //put a random element
        }
    }
}

void print_matrix(int *a[], int size[])
{

    for (int i = 0; i < 6; ++i) //to print the matrix, loop through it
    {

        for (int j = 0; j < size[i]; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void change(int *a[], int size[], int row, int newsize) // to reallocate matrix columns
{
    a[row - 1] = (int *)realloc(a[row-1], sizeof(int) * newsize); // reallocate the current size with newsize (this changes no of columns)
    if (size[row - 1] < newsize) //if the newsize is larger than old size, then new elements need to be randomly assigned values
    {
        for (int j = size[row - 1]; j < newsize; ++j)
        {
            a[row-1][j] = (rand() % (9 - 2 + 1)) + 2; //randomly assign a number for the new elements
        }
    }
    size[row - 1] = newsize; //change size to newsize for the row where the reallocation took place
}

int main()
{
    srand(time(0)); //initialise the seed
    int *a[6]; //create array of pointers
    int size[] = {7, 4, 6, 3, 7, 2}; //initial sizes of each row

    generate_matrix(a, size); //generate matrix with the predefined sizes (part a)
    printf("The matrix looks like as follows:\n");
    print_matrix(a, size); //print the matrix

    char ch;
    printf("\nDo you want to change columns of any row? (Y/n) ");
    scanf("%c", &ch);

    while ((ch == 'y')|| (ch == 'Y')) //menu driven program
    {
        int row, newsize;
        printf("\nEnter row number (1-6) whose columns are to be modified: ");
        scanf("%d", &row);
        printf("\nEnter new number of columns: ");
        scanf("%d", &newsize);

        change(a, size, row, newsize); //change matrix accordingly

        print_matrix(a, size); //print matrix

        printf("\nDo you want to change columns of any row again? (Y/n) ");
        getchar();      
        scanf("%c", &ch);
    }

    return 0;
}