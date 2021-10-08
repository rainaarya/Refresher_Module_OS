#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; ++i) //perform the loop size-1 times
    {

        for (int j = 0; j < size - i - 1; ++j) // j<size-i-1 since last i elements are sorted already
        {

            if (arr[j] > arr[j + 1]) //compare jth index element with j+1th index element, if it's greater then do following
            {
                //perform swap

                int temp = arr[j];   //assign a temp variable to value of arr[j]
                arr[j] = arr[j + 1]; //put arr[j+1] value inside arr[j]
                arr[j + 1] = temp;   //assign arr[j+1] to the previously stored temp variable
            }
        }
    }
}

void selectionSort(int arr[], int size)
{

    for (int i = 0; i < (size - 1); i++) // perform the loop size-1 times
    {
        int min_pos = i;                   //assume i is the index of minimum element
        for (int j = i + 1; j < size; j++) //loop from i+1 index to end of array
        {
            if (arr[min_pos] > arr[j]) //compare min_pos index element to current element
                min_pos = j;           //if the current element is lesser, assign min_pos to current element index
        }
        if (min_pos != i) //After loop, check if our assumption holds, if it doesn't then
        {
            //perform swap
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
}

int main()
{
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the array elements: ");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &arr[i]);
    }

    char ch; //ask if user wants to sort using bubble or selection
    printf("\nDo you want to use Bubble Sort or Selection Sort? (Input 'B' for bubble sort or 'S' for selection sort): ");
    getchar();
    scanf("%c", &ch);

    if (ch == 'b' || ch == 'B')
    {
        bubbleSort(arr, size); //sort using bubble sort
        printf("\nSorted array using bubble sort is: ");
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", arr[i]);
        }
    }

    else if (ch == 'S' || ch == 's')
    {
        selectionSort(arr, size); //sort using selection sort
        printf("\nSorted array using Selection sort is: ");
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}