#include <stdio.h>
#include <math.h>

void addition(int a, int b)
{
    printf("\nAddition is %d\n", a + b);
}
void subtraction(int a, int b)
{
    printf("\nSubtraction is %d\n", a - b);
}
void division(int a, int b)
{
    printf("\nDivision is %.2f\n", (float)a / (float)b);
}
void multiplication(int a, int b)
{
    printf("\nMultiplication is %d\n", a * b);
}

void exponentiation(int a, int b)
{
    printf("\nExponentiation is %.2f\n", pow(a, b));
}

int main()
{
    // type is an array of function pointers
    void (*type[])(int, int) = {&addition, &subtraction, &division, &multiplication, &exponentiation};
    int choice;

    int a, b;
    printf("Enter values for num1 and num2: ");
    scanf("%d %d",&a,&b);

    printf("\n0:To Add\n1:To Subtract\n2:To Divide\n3:To Multiply\n4:For Exponentiation \n");
    printf("Enter your choice(0-4): ");
    scanf("%d", &choice);

    if (choice <0 || choice > 4)
        printf("\nInvalid choice");

    (*type[choice])(a, b);

    return 0;
}
