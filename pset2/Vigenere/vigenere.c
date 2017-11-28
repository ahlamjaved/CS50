#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    // checks to see if user inputs only 2 arguments
    if (argc != 2)
    {
        printf("Please Try Again\n");
        return 1;
    }
    // Checks to see if the inputted argument is alpha characters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Please Try Again\n");
            return 1;
        }
    }

    // asks user to input a string to encrypt
    printf("plaintext: ");

    string string = get_string();

    // once argv is checked for correct number of input, place in variable k to begin the cipher
    int k = 0;

    printf("ciphertext: ");

    // goes thru the string and if the character is not a letter, it'll print it as is
    for (int i = 0, n = strlen(string); i < n ; i++ )
    {
        // keeps looping through the inputting string
        k = k % strlen(argv[1]);

            if (isalpha(string[i]))
            {
              // the if- else if  condition determines if the character is upper or lower case then converts it based on k
                if (islower(string[i]) && islower(argv[1][k]))
                {
                    printf("%c", (((string[i] - 97) + (argv[1][k] - 97)) % 26) + 97);
                }
                else if (isupper(string[i]) && isupper(argv[1][k]))
                {
                    printf("%c", (((string[i] - 65) + (argv[1][k] - 65)) % 26) + 65);
                }
                else if (isupper(string[i]) && islower(argv[1][k]))
                {
                    printf("%c", (((string[i] - 65) + (argv[1][k] - 97)) % 26) + 65);
                }
                else if (islower(string[i]) && isupper(argv[1][k]))
                {
                  printf("%c", (((string[i] - 97) + (argv[1][k] - 65)) % 26) + 97);
                }
                k++;
            }
            // if the character is neither upper or lower case i.e non letter character
           else
           {
               printf("%c", string[i]);
           }
    }
    printf("\n");
    return 0;
}