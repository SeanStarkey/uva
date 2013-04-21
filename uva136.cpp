/*
 * UVa Online Judge - Problem 136 - Ugly Numbers
 */

#include <iostream>
#include <vector>
#include <algorithm>

unsigned long ipow(unsigned radix, unsigned power)
{
    unsigned long product = 1;
    for (int i=0; i<power; i++)
        product *= radix;
    return product;
}

int main()
{
    const unsigned long limit = 1000000000;
    std::vector<unsigned long> uglies;
    unsigned two = 0;
    unsigned three = 0;
    unsigned five = 0;
    unsigned long product = 1;
    while (product < limit)
    {
        while (product < limit)
        {
            while (product < limit)
            {
                uglies.push_back(product);
                five++;
                product = ipow(2, two) * ipow(3, three) * ipow(5, five);
            }
            uglies.push_back(product);
            three++;
            five = 0;
            product = ipow(2, two) * ipow(3, three);
        }
        uglies.push_back(product);
        two++;
        three = 0;
        five = 0;
        product = ipow(2, two);
    }
    std::sort(uglies.begin(), uglies.end());

    std::cout << "The 1500'th ugly number is " << uglies[1499] << "." << std::endl;
}
