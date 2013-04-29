/*
 * UVa - Probelm 299
 */

#include <iostream>

unsigned determineSwaps(unsigned train[51], unsigned length)
{
    int swaps = 0;

    for (int i=(length-1); i>=0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (train[j] > train[j+1])
            {
                int swap = train[j+1];
                train[j+1] = train[j];
                train[j] = swap;
                swaps++;
            }
        }
    }

    return swaps;
}

int main()
{
    unsigned numberCases;
    std::cin >> numberCases;

    for (int testCase=0; testCase<numberCases; testCase++)
    {
        unsigned numberCars;
        std::cin >> numberCars;

        unsigned train[51];
        for (int car=0; car<numberCars; car++)
        {
            std::cin >> train[car];
        }

        int swaps = determineSwaps(train, numberCars);
        std::cout << "Optimal train swapping takes " << swaps << " swaps." << std::endl;
    }

    return 0;
}
