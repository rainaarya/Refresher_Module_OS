#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_matrix(int *a[], int size[])
{

    for (int i = 0; i < 6; ++i)
    {
        a[i] = (int *)malloc(size[i] * sizeof(int));
        for (int j = 0; j < size[i]; ++j)
        {
            a[i][j] = (rand() % (9 - 2 + 1)) + 2;
        }
    }
}

void print_matrix(int *a[], int size[])
{

    for (int i = 0; i < 6; ++i)
    {

        for (int j = 0; j < size[i]; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void change(int *a[], int size[], int row, int newsize)
{
    a[row - 1] = (int *)realloc(a[row-1], sizeof(int) * newsize);
    if (size[row - 1] < newsize)
    {
        for (int j = size[row - 1]; j < newsize; ++j)
        {
            a[row-1][j] = (rand() % (9 - 2 + 1)) + 2;
        }
    }
    size[row - 1] = newsize;
}

int main()
{
    srand(time(0));
    int *a[6];
    int size[] = {7, 4, 6, 3, 7, 2};

    generate_matrix(a, size);
    printf("The matrix looks like as follows:\n");
    print_matrix(a, size);

    char ch;
    printf("\nDo you want to change columns of any row? (Y/n) ");
    scanf("%c", &ch);

    while ((ch == 'y')|| (ch == 'Y'))
    {
        int row, newsize;
        printf("\nEnter row number (1-6) whose columns are to be modified: ");
        scanf("%d", &row);
        printf("\nEnter new number of columns: ");
        scanf("%d", &newsize);

        change(a, size, row, newsize);

        print_matrix(a, size);

        printf("\nDo you want to change columns of any row again? (Y/n) ");
        getchar();      
        scanf("%c", &ch);
    }

    return 0;
}