#include <stdio.h>

/* function definition to swap the values */
void swap_var(int *x, int *y)
{

    int temp;
    temp = *x; // save the value present in address x
    *x = *y;   // perform x=y
    *y = temp; // put temp value into address y
}

void swap_arr(int a1[], int a2[], int s)
{
    for (int i = 0; i < s; ++i) //perform loop till size of array is reached
    {
        int temp = a1[i];   //save the value present in a1[i] into temp
        a1[i] = a2[i];      //perform swap by a1[i]=a2[i]
        a2[i] = temp;       //put the temp value into a2[i]
    }
}

int main()
{

    int a, b;

    printf("Enter two variables a and b: ");
    scanf("%d %d", &a, &b);
    printf("\nBefore Swapping, a = %d and b = %d", a, b);
    swap_var(&a, &b); //pass the address of a and b as arguments
    printf("\nAfter Swapping, a = %d and b = %d", a, b);

    int size;
    printf("\n\nEnter a size of first array/second array(since both should have same size): ");
    scanf("%d", &size);
    int a1[size];
    int a2[size];
    printf("Enter array elements of 1st array: ");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &a1[i]);  //read array 1 elements
    }

    printf("Enter array elements of 2nd array: ");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &a2[i]);  //read array 2 elements
    }

    printf("\nArray elements of 1st array before swap: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a1[i]);
    }

    printf("\nArray elements of 2nd array before swap: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a2[i]);
    }

    swap_arr(a1, a2, size);   //perform swap of the arrays

    //print output
    printf("\n\nArray elements of 1st array after swap: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a1[i]);
    }

    printf("\nArray elements of 2nd array after swap: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", a2[i]);
    }

    printf("\n");

    return 0;
}