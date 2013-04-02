/*
 * UVa - Problem 272 - TeX Quotes
 *
 */

#include <stdio.h>

int main()
{
    int c = getchar();
    bool open = true;
    do
    {
        if (c == '\"')
        {
            if (open)
            {
                putchar('`');
                putchar('`');
                open = false;
            }
            else
            {
                putchar('\'');
                putchar('\'');
                open = true;
            }
        }
        else
        {
            putchar(c);
        }
        c = getchar();
    } while (c != EOF);

    return 0;
}
