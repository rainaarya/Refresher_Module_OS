#include <stdio.h>

void reverse(char str[])
{
    int len;
    for (len = 0; str[len] != '\0'; len++)
        ;
    if (str[len - 1] == '\n') //To remove newline character at the end of the String due to fgets() behaviour
    {
        str[len - 1] = '\0';
        len--;
    }

    for (int i = 0; i < len / 2; i++)
    {
        char ch = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = ch;
    }
}

int main()
{

    char str[101];
    printf("Enter the string (Max 100 characters): ");
    fgets(str, sizeof(str) + 1, stdin);
    printf("\nThe string before reversal: ");
    printf("%s", str);
    reverse(str);
    printf("The string after reversal: ");
    printf("%s\n", str);

    return 0;
}