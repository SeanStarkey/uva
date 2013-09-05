/*
 * UVa Online Judge - Problem 10079
 */

#include <iostream>

int main()
{
    while (1)
    {
        long cuts;
        std::cin >> cuts;
        if (cuts < 0)
            return 0;

        long pieces = (cuts*cuts + cuts + 2)/2;
        std::cout << pieces << "\n";
    }
    return 0;
}
