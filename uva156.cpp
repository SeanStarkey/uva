/**
 * UVa Online Judge - Problem 156
 */

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

unsigned long primes[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                          31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                          73, 79, 83, 89, 97, 101};
struct WordHash {
    unsigned long firstHalf;
    unsigned long secondHalf;
    WordHash() : firstHalf(1), secondHalf(1) {};
};
struct WordHashCompare
{
    bool operator()( WordHash const& lhs, WordHash const& rhs ) const
    {
        if (lhs.firstHalf < rhs.firstHalf)
            return true;
        if (lhs.firstHalf > rhs.firstHalf)
            return false;
        if (lhs.secondHalf < rhs.secondHalf)
            return true;
        if (lhs.secondHalf > rhs.secondHalf)
            return false;
        return false;
    }
};
std::vector<std::string> wordVector;
std::vector<WordHash> hashVector;
std::vector<bool> ananagramVector;
std::map<WordHash, unsigned, WordHashCompare> wordMap;
unsigned numberOfWords;
std::list<std::string> ananagramList;

WordHash analyzeWord(std::string word)
{
    WordHash hash;
    for (int index=0; index<word.length(); index++)
    {
        int asciiValue = word[index] - 'A';
        if (asciiValue > 26)
            asciiValue = word[index] - 'a';
        if ((asciiValue >= 0) && (asciiValue <= 13))
            hash.firstHalf *= primes[asciiValue];
        if ((asciiValue >= 14) && (asciiValue <= 26))
            hash.secondHalf *= primes[asciiValue-14];
    }
    return hash;
}

int main()
{
    numberOfWords = 0;
    while (std::cin.good())
    {
        std::string word;
        std::cin >> word;
        if (word == "#")
            break;

        WordHash hash = analyzeWord(word);
        wordVector.push_back(word);
        hashVector.push_back(hash);
        ananagramVector.push_back(true);
    }
    unsigned length = wordVector.size();
    for (unsigned index=0; index<length; index++)
    {
        std::map<WordHash, unsigned, WordHashCompare>::iterator iter =
            wordMap.find(hashVector[index]);
        if (iter == wordMap.end())
        {
            wordMap[hashVector[index]] = index;
        }
        else
        {
            ananagramVector[iter->second] = false;
            ananagramVector[index] = false;
        }
    }
    for (unsigned index=0; index<length; index++)
    {
        if (ananagramVector[index])
        {
            ananagramList.push_back(wordVector[index]);
        }
    }
    ananagramList.sort();
    std::list<std::string>::iterator iter;
    for (iter = ananagramList.begin(); iter != ananagramList.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
}
