/*
 * UVa Online Judge - Problem 575
 */

#include <iostream>
#include <stdlib.h>
#include <string>

int convert(char c)
{
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    }
    return 0;
}

int main()
{
    while (1)
    {
        std::string line;
        std::getline(std::cin, line);
        if (line == "0")
            return 0;
        unsigned long value = 0;
        int end = line.length();
        for (int i=0; i<end; i++)
        {
            value += convert(line[i]) * ((2<<(end-i-1))-1);
        }
        std::cout << value << "\n";
    }
    return 0;
}
