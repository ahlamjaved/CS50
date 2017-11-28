#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string();
    // to see if the input is greater than what can be accepted
    if (s != NULL)
    {
        // print the first letter in the first string as an uppercase
        if (s[0] != ' ')
        {
          printf("%c", toupper(s[0]));
        }
        // to see if the next character is a space or not
        for (int i = 0, n = strlen(s); i < n ; i++ )
        {
            // if the next character is a space then print the first letter as uppercase
            if(s[i] == ' ' && s[ i + 1] != ' ' && s[ i + 1] != '\0')
            {
                printf("%c", toupper(s[i+1]));
            }
        }
    }
    printf("\n");
}