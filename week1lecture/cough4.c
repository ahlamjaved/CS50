#include <stdio.h>

void cough(int n);

int main (void)
{
    cough(3)
}

void cough(int n)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Cough\n");
    }
}