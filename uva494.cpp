/*
 * UVa Online Judge - Problem 494
 */

#include <iostream>
#include <ctype.h>

int main()
{
    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        if (!std::cin.good())
            break;

        int numberOfWords = 0;
        bool inword = false;
        for (int i=0; i<line.size(); i++)
        {
            if (!inword)
            {
                if (isalpha(line[i]))
                {
                    inword = true;
                    numberOfWords++;
                }
            }
            else
            {
                if (!isalpha(line[i]))
                {
                    inword = false;
                }
            }

        }
        std::cout << numberOfWords << std::endl;
    }
    return 0;
}
