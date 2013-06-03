/*
 * UVa Online Judge - Problem 10370
 */

#include <iostream>
#include <iomanip>

int main()
{
    int testCases;

    std::cin >> testCases;
    for (int testCase=0; testCase<testCases; testCase++)
    {
        int peopleScores[1001];
        int numberPeople;
        int total = 0;
        std::cin >> numberPeople;
        for (int people=0; people<numberPeople; people++)
        {
            std::cin >> peopleScores[people];
            total += peopleScores[people];
        }
        float average = (float)total/numberPeople;
        int aboveAverage = 0;
        for (int people=0; people<numberPeople; people++)
        {
            if (peopleScores[people] > average)
                aboveAverage++;
        }
        float percentage = (float)aboveAverage/numberPeople*100.0;
        std::cout << std::fixed << std::setprecision(3) << percentage << "%\n";
    }
    return 0;
}
