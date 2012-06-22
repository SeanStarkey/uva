/**
 * UVa Online Judge - Problem 10055
 *
 */
#include <iostream>

int main()
{
    unsigned long first;
    unsigned long second;
    while (std::cin.good())
    {
        std::cin >> first;
        std::cin >> second;
        if (std::cin.fail())
        {
            return 0;
        }

        if (second > first)
        {
            unsigned long answer = second - first;
            std::cout << answer << "\n";
        }
        else
        {
            unsigned long answer = first - second;
            std::cout << answer << "\n";
        }
    }
}
