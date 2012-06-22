/**
 * UVa Online Judge - Problem 100
 *
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
 */

#include <iostream>

unsigned nextStep(unsigned num)
{
    if (num%2 == 1)
    {
        return 3*num + 1;
    }
    return num/2;
}

unsigned determineNumberOfSteps(unsigned num)
{
    unsigned steps = 1;

    while (num != 1)
    {
        num = nextStep(num);
        steps++;
    }
    return steps;
}

int main()
{
    unsigned first;
    unsigned second;
    unsigned start;
    unsigned end;
    while (std::cin.good())
    {
        unsigned result = 0;
        std::cin >> first;
        std::cin >> second;
        if (std::cin.fail())
        {
            return 0;
        }

        if (first < second)
        {
            start = first;
            end = second;
        }
        else
        {
            start = second;
            end = first;
        }

        for (unsigned i = start; i <= end; i++)
        {
            unsigned numberOfSteps = determineNumberOfSteps(i);
            if (numberOfSteps > result)
            {
                result = numberOfSteps;
            }
        }
        std::cout << first << " " << second << " " << result << "\n";
    };
}
