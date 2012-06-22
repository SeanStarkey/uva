/**
 * UVa Online Judge - Problem 151
 *
 */

#include <iostream>

void clearArray(const int number, bool (&regions)[100])
{
    for (int i = 1; i<=number; i++)
    {
        regions[i] = false;
    }
}

int main()
{
    unsigned number;
    // for (number=13; number < 100; number++)
    // {
    while (std::cin.good())
    {
        std::cin >> number;
        if (number == 0)
        {
            return 0;
        }
        if (std::cin.fail())
        {
            return 0;
        }

        unsigned m;
        for (m = 1; m < number; m++)
        {
            bool regions[100];
            clearArray(number, regions);
            unsigned iter = 0;
            unsigned power = 1;
            while (iter < number)
            {
                // std::cout << power << " ";
                regions[power] = true;
                iter++;
                if (iter == number)
                {
                    // std::cout << "B: " << power;
                    break;
                }

                unsigned times_to_move = m;
                while (times_to_move > 0)
                {
                    //std::cout << "p: " << power << " ";
                    power++;
                    if (power > number)
                        power = 1;
                    if (!regions[power])
                        times_to_move--;
                }
            }
            if (power == 13)
            {
                // std::cout << "*** " << m << "\n";
                break;
            }
            // std::cout << "\n";
        }
        std::cout << m << "\n";
    }
}

