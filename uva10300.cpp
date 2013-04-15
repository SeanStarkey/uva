/*
 * UVa Online Judge - Problem 10300
 */

#include <iostream>

typedef struct
{
    int farmsize;
    int animals;
    int environment;
} farmer;

farmer farmers[20];

int main()
{
    int testcases;

    std::cin >> testcases;
    for (int testcase=0; testcase<testcases; testcase++)
    {
        int numberFarmers;
        std::cin >> numberFarmers;
        float totalCost = 0;
        for (int farmerIndex=0; farmerIndex<numberFarmers; farmerIndex++)
        {
            std::cin >> farmers[farmerIndex].farmsize;
            std::cin >> farmers[farmerIndex].animals;
            std::cin >> farmers[farmerIndex].environment;

            totalCost += 1.0 * farmers[farmerIndex].farmsize /
                farmers[farmerIndex].animals *
                farmers[farmerIndex].environment *
                farmers[farmerIndex].animals;
        }
        std::cout << totalCost << std::endl;
    }
    return 0;
}
