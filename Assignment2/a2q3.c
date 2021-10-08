#include <stdio.h>
#include <math.h>

void addition(int a, int b)
{
    printf("\nAddition is %d\n", a + b);    //print addition
}
void subtraction(int a, int b)
{
    printf("\nSubtraction is %d\n", a - b); //print difference
}
void division(int a, int b)
{
    printf("\nDivision is %.2f\n", (float)a / (float)b);    //print division
}
void multiplication(int a, int b)
{
    printf("\nMultiplication is %d\n", a * b);      //print product
}

void exponentiation(int a, int b)
{
    printf("\nExponentiation is %.2f\n", pow(a, b));    //print exponentiaion
}

int main()
{
    // 'type' is an array of function pointers
    void (*type[])(int, int) = {&addition, &subtraction, &division, &multiplication, &exponentiation};   //assign the addresses of the functions in the function pointer array
    int choice;

    int a, b;
    printf("Enter values for num1 and num2: "); //take inputs
    scanf("%d %d", &a, &b);

    printf("\n0:To Add\n1:To Subtract\n2:To Divide\n3:To Multiply\n4:For Exponentiation \n");
    printf("Enter your choice(0-4): ");      //ask the user for the required operation
    scanf("%d", &choice);

    if (choice < 0 || choice > 4)
    {
        printf("\nInvalid choice\n");
        return 0;
    }

    (*type[choice])(a, b);  //call the function appropriately from the array of function pointers

    return 0;
}
