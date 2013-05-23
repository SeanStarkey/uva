/*
 * UVa Online Judge - Problem 591
 */

#include <iostream>

int abs(int x)
{
    if (x<0)
        return -x;
    else
        return x;
}

int main()
{
    int set = 1;
    while (true)
    {
        int number;
        std::cin >> number;
        if (number == 0)
            return 0;

        int stacks[50];
        int total = 0;
        for (int i=0; i<number; i++)
        {
            std::cin >> stacks[i];
            total += stacks[i];
        }
        int average = total/number;
        int difference = 0;
        for (int i=0; i<number; i++)
        {
            difference += abs(average - stacks[i]);
        }
        std::cout << "Set #" << set++ << std::endl;
        std::cout << "The minimum number of moves is " << difference/2 << "." << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
