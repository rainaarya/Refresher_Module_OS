#include <stdio.h>

void reverse(char str[])
{
    int len;
    for (len = 0; str[len] != '\0'; len++) //to get the length of the string
        ;
    if (str[len - 1] == '\n') //To remove newline character at the end of the String due to fgets() behaviour
    {
        str[len - 1] = '\0';
        len--;               //decrement the len as newline has been removed from string contents
    }

    for (int i = 0; i < len / 2; i++) // perform loop till half the length of string
    {
        char ch = str[i];   //save the element in str[i] in a temporary char variable ch
        str[i] = str[len - i - 1];  // swap the current element with the len - i - 1  index element
        str[len - i - 1] = ch;   //put the saved ch variable value into str[len-i-1]
    }
}

int main()
{

    char str[102];
    printf("Enter the string (Max 100 characters): ");
    fgets(str, sizeof(str), stdin); // to get the string
    printf("\nThe string before reversal: ");
    printf("%s", str);
    reverse(str); // to reverse the string
    printf("The string after reversal: ");
    printf("%s\n", str);

    return 0;
}