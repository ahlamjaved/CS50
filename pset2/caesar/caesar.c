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

    // once argv is checked for correct number of input, place in variable k to begin the cipher
    int k = atoi(argv[1]);

    // make sure integer is not a negative value
    if (k < 0)
    {
        printf("Please Try Again\n");
        return 1;
    }

    printf("plaintext: ");


    // ask user to input a string to cipher

    string string= get_string();
    printf("ciphertext: ");
    for (int i = 0, n = strlen(string); i < n ; i++ )
    {
        // the if- else if  condition determines if the character is upper or lower case then converts it based on k
        if (islower(string[i]))
        {
            printf("%c", (((string[i] + k) - 97) % 26) + 97 );
        }
        else if (isupper(string[i]))
        {
            printf("%c", (((string[i] + k) - 65) % 26) + 65);
        }
        // if the character is neither upper.  or lower case i.e non letter character
        else
        {
            printf("%c", string[i]);
        }
    }
    printf("\n");
}
