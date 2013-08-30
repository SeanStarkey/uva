/*
 * UVa Online Judge - Problem 483
 */

#include <iostream>
#include <string>

int main()
{
    bool firstLine = true;
    while (true)
    {
        std::string line;
        getline(std::cin, line);
        if (!std::cin.good())
        {
            return 0;
        }

        int widx = 0;
        char word[102400];
        bool firstWord = true;
        for (int i=0; i<line.length(); i++)
        {
            if (line[i] != ' ')
            {
                word[widx++] = line[i];
            }
            else
            {
                if (firstWord)
                {
                    firstWord = false;
                }
                else
                {
                    std::cout << ' ';
                }
                for (int j=widx-1; j>=0; j--)
                    std::cout << word[j];
                widx = 0;
            }
        }
        if (!firstWord)
            std::cout << ' ';
        for (int j=widx-1; j>=0; j--)
            std::cout << word[j];
        std::cout << "\n";
    }
    return 0;
}
