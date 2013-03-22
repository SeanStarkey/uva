/*
 * UVa - Problem 458 - The Decoder
 *
 */

#include <stdio.h>

int main()
{
    int c = getchar();
    do
    {
        if (c < 15)
            putchar(c);
        else
            putchar(c-7);
        c = getchar();
    } while (c != EOF);
}
