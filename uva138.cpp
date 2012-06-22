/**
 * UVa Online Judge - Problem 138
 *
 */

#include <iostream>
#include <iomanip>


int main()
{
    unsigned long long currentHouseNumber = 2;
    unsigned long long leftSum = 0;
    unsigned long long found = 0;
    unsigned long long rightSum = 0;
    unsigned long long endNumber = 2;
    while (found < 10)
    {
        leftSum += (currentHouseNumber-1);

        while (rightSum < leftSum) {
            endNumber++;
            rightSum += endNumber;
        }

        if (leftSum == rightSum)
        {
            std::cout << std::setw(10) << currentHouseNumber;
            std::cout << std::setw(10) << endNumber << std::endl;
            found++;
        }

        currentHouseNumber++;
        rightSum -= currentHouseNumber;
    }
}

