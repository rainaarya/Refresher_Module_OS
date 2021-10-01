#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; ++i)
    {

        for (int j = 0; j < size - i - 1; ++j)
        {

            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size)
{

    for (int i = 0; i < (size - 1); i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_pos] > arr[j])
                min_pos = j;
        }
        if (min_pos != i)
        {
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

    char ch;
    printf("\nDo you want to use Bubble Sort or Selection Sort? (Input 'B' for bubble sort or 'S' for selection sort): ");
    getchar();
    scanf("%c", &ch);

    if (ch == 'b' || ch == 'B')
    {
        bubbleSort(arr, size);
        printf("\nSorted array using bubble sort is: ");
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", arr[i]);
        }
    }

    else if (ch == 'S' || ch == 's')
    {
        selectionSort(arr, size);
        printf("\nSorted array using Selection sort is: ");
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}