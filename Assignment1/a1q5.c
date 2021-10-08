#include <stdio.h>
#include <stdlib.h>

void bub_sort(unsigned int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {

        for (int j = i + 1; j < size; ++j)
        {

            if (a[i] > a[j])
            {

                unsigned int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int binary_search(unsigned int a[], int size, unsigned int key)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == key)
            return mid;

        if (a[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);
    unsigned int a[size]; // to declare an array of unsigned integers
    unsigned int key;

    printf("\nEnter array elements: ");
    for (int i = 0; i < size; ++i)
    {
        scanf("%u", &a[i]);
    }

    bub_sort(a, size); // to sort the elements before binary search
    printf("Sorted array would be: ");
    for (int i = 0; i < size; ++i)
    {
        printf("%u ", a[i]);
    }

    printf("\n\nEnter key to be searched: ");
    scanf("%u", &key);

    int val = binary_search(a, size, key);

    if (val == -1)
    {
        printf("Key does not exist in array");
    }
    else
    {
        printf("Key found sucessfully in array at position %d of sorted array", val + 1);
    }

    return 0;
}