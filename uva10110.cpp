/*
 * UVa Online Judge - Problem 10110
 */

#include <iostream>
#include <math.h>
#include <map>

int main()
{
    while (1)
    {
        unsigned long number;
        std::cin >> number;
        if (number == 0)
            return 0;

        std::map<unsigned long,unsigned long> factors;
        while (number%2 == 0)
        {
            number /= 2;
            factors[2]++;
        }

        unsigned long i = 3;
        float sqrtNumber = sqrt(number)+1;
        while (i < sqrtNumber)
        {
            if (number == (number/i)*i)
            {
                number /= i;
                factors[i]++;
                sqrtNumber = sqrt(number)+1;
            }
            else
            {
                i += 2;
            }
        }
        if (number != 1)
            factors[number]++;

        unsigned numberDivsors = 1;
        for (std::map<unsigned long,unsigned long>::iterator it = factors.begin(); it != factors.end(); it++)
        {
            numberDivsors *= (it->second + 1);
            //           std::cout << it->first << ":" << it->second << "\n";
        }
        std::cout << (numberDivsors%2==1 ? "yes\n" : "no\n");
    }
    return 0;
}
