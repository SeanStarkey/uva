/**
 * UVa Online Judge - Problem 10038 - Jolly Jumpers
 */

#include <iostream>
#include <vector>
#include <algorithm>

int absDiff(int x, int y)
{
    if (x < y)
        return y - x;
    else
        return x - y;
}

int main()
{
    while (std::cin.good())
    {
        unsigned numberOfInts;
        std::cin >> numberOfInts;
        if (!std::cin.good())
            break;

        std::vector<int> ints;
        for (int i=0; i<numberOfInts; i++)
        {
            int nextInt;
            std::cin >> nextInt;
            ints.push_back(nextInt);
        }

        std::vector<int> abs;
        for (int i=0; i<(numberOfInts-1); i++)
        {
            abs.push_back(absDiff(ints[i], ints[i+1]));
        }

        bool jolly = true;
        std::sort(abs.begin(), abs.end());
        for (int i=0; i<(numberOfInts-1); i++)
        {
            if (abs[i] != (i+1))
            {
                jolly = false;
                break;
            }
        }

        if (jolly)
            std::cout << "Jolly" << std::endl;
        else
            std::cout << "Not jolly" << std::endl;
    }
    return 0;
}
