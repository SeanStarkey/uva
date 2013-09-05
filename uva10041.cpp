/*
 * UVa Online Judge - Problem 10041
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int testCases;

    std::cin >> testCases;

    for (int t=0; t<testCases; t++)
    {
        int relatives;
        std::cin >> relatives;
        int sum = 0;
        std::vector<int> numbers;
        numbers.resize(relatives);
        for (int r=0; r<relatives; r++)
        {
            std::cin >> numbers[r];
            sum += numbers[r];
        }
        std::sort(numbers.begin(), numbers.end());
        int address = numbers[relatives/2];
        int relativeSum = 0;
        for (int r=0; r<relatives; r++)
        {
            if (numbers[r] < address)
                relativeSum += address - numbers[r];
            else
                relativeSum += numbers[r] - address;
        }
        std::cout << relativeSum << "\n";
    }
    return 0;
}
