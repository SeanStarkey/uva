/*
 * UVa Online Judge - Problem 10008
 */

#include <iostream>
#include <ctype.h>

int main()
{
    int charCount[26];
    for (int i=0; i<26; i++)
        charCount[i] = 0;

    int numberOfLines;
    std::cin >> numberOfLines;
    std::string line;
    std::getline(std::cin, line);
    int max = 0;
    for (int lineCount = 0; lineCount<numberOfLines; lineCount++)
    {
        std::getline(std::cin, line);
        for (int c=0; c<line.length(); c++)
        {
            char ch = line[c];
            if (isalpha(ch))
            {
                int offset = toupper(ch) - 'A';
                charCount[offset]++;
                if (charCount[offset] > max)
                    max = charCount[offset];
            }
        }
    }
    for (int j=max; j>0; j--)
    {
        for (int i=0; i<26; i++)
        {
            if (charCount[i] == j)
                std::cout << (char)('A'+i) << " " << charCount[i] << "\n";
        }
    }
    return 0;
}

