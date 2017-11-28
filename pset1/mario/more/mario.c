#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        printf("height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);

    for  (int row = 1; row <= height; row = row + 1)
    {

        for (int space = height - row; space > 0; space--)
        {
            printf(" ");
        }
        for (int hashtag = 1; hashtag < row + 1; hashtag++)
        {
            printf("#");
        }
        printf("  ");
        for (int hashtag2 = 1; hashtag2 < row +1; hashtag2++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}




