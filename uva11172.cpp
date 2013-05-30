/*
 * UVa Online Judge - Problem 11172
 */

#include <iostream>

int main()
{
    int sets;
    std::cin >> sets;
    for (int i=0; i<sets; i++)
    {
        long a;
        long b;
        std::cin >> a;
        std::cin >> b;

        if (a > b)
            std::cout << ">\n";
        else if (a < b)
            std::cout << "<\n";
        else
            std::cout << "=\n";
    }
    return 0;
}
