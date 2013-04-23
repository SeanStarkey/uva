/*
 * UVa Online Judge - Problem 10018
 */

#include <iostream>

unsigned flip(const unsigned number)
{
    unsigned working = number;
    unsigned result = 0;
    while (working > 0)
    {
        unsigned digit = working%10;
        working = working/10;

        result = result * 10 + digit;
    }
    return result;
}


void palindrome(const unsigned number, unsigned & iterations, unsigned & final)
{
    unsigned numberToTest = number;
    iterations = 0;
    while (true)
    {
        unsigned flipped = flip(numberToTest);
        if (flipped == numberToTest)
        {
            final = numberToTest;
            return;
        }
        numberToTest = numberToTest + flipped;
        iterations++;
    }
}

int main()
{
    unsigned numberOfTests;

    std::cin >> numberOfTests;

    for (unsigned i=0; i<numberOfTests; i++)
    {
        unsigned number;
        std::cin >> number;
        unsigned iterations;
        unsigned final;
        palindrome(number, iterations, final);
        std::cout << iterations << " " << final << std::endl;
    }
    return 0;
}
