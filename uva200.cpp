/**
 * UVa Online Judge - Problem 200
 */

#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

typedef std::set<char> Set;

struct Letter
{
    Letter(const char in) {
        thisLetter = in;
    }

    char thisLetter;

    Set before;
    Set after;
};

typedef std::map<char, Letter*> Map;
typedef std::vector<Letter*> List;

void dump(Letter* l);
void dumpList();
void dump();

Map letterMap;
List letterList;

Letter* getLetter(char letterChar)
{
    Map::iterator i = letterMap.find(letterChar);
    Letter* ret;
    if (i == letterMap.end())
    {
        ret = new Letter(letterChar);
        letterMap.insert(std::pair<char, Letter*>(letterChar, ret));
    }
    else
    {
        ret = (*i).second;
    }

    return ret;
}

void compareLetters(const std::string& prev, const unsigned& prevLength,
                    const std::string& curr, const unsigned& currLength)
{
    unsigned amount = std::min(prevLength, currLength);
    for (unsigned comparePlace=0; comparePlace < amount; comparePlace++)
    {
        if (prev[comparePlace] != curr[comparePlace])
        {
            Letter* prevLetter = getLetter(prev[comparePlace]);
            Letter* currLetter = getLetter(curr[comparePlace]);
            prevLetter->after.insert(curr[comparePlace]);
            currLetter->before.insert(prev[comparePlace]);
            return;
        }
    }
}

bool compare(Letter* l, Letter* r)
{
//    std::cout << "C: " << l->thisLetter << " " << r->thisLetter << std::endl;
    if (l->before.size() == 0)
    {
        return true;
    }
    if (l->after.size() == 0)
    {
        return false;
    }

    if (r->before.size() == 0)
    {
        return false;
    }
    if (r->after.size() == 0)
    {
        return true;
    }

    if (l->after.find(r->thisLetter) != l->after.end())
    {
        return true;
    }

    if (r->before.find(l->thisLetter) != r->before.end())
    {
        return false;
    }

    std::cout << "============" << std::endl;
    std::cout << "END " << l->thisLetter << " " << r->thisLetter << std::endl;
    dump(l);
    dump(r);
    return true;
}

void sortLetters()
{
    //dump();
    for (Map::iterator i=letterMap.begin(); i!=letterMap.end(); i++)
    {
        letterList.push_back((*i).second);
        //std::sort(letterList.begin(), letterList.end(), compare);
    }
    unsigned size = letterList.size();
    unsigned loc1 = 0;
    unsigned loc2 = 1;
    //dumpList();
    while (loc2 < size)
    {
        loc1 = 0;
        Letter* right = letterList[loc2];
        while (loc1 < loc2)
        {
            //std::cout << loc1 << " " << loc2 << " ";
            //dumpList();
            Letter* left = letterList[loc1];
            if (left->before.find(right->thisLetter) != left->before.end() ||
                right->after.find(left->thisLetter) != right->after.end() ||
                right->before.size() == 0)
            {
                Letter* swap = left;
                letterList[loc1] = right;
                letterList[loc2] = swap;
                //std::cout << "S:" << loc1 << " " << loc2 << " ";
                //dumpList();
                loc1 = 0;
                //loc2 = 1;
                right = letterList[loc2];
            }
            else
            {
                loc1++;
            }
        }
        loc2++;
    }
}

void dump(Letter* l)
{
    std::cout << "-------" << std::endl;
    std::cout << "Letter: " << l->thisLetter << std::endl;

    std::cout << "Before: ";
    for (Set::iterator i2=l->before.begin();
         i2!=l->before.end(); i2++)
    {
        std::cout << *i2 << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (Set::iterator i2=l->after.begin();
         i2!=l->after.end(); i2++)
    {
        std::cout << *i2 << " ";
    }
    std::cout << std::endl;
}

void dumpList()
{
    std::cout << "-------" << std::endl;
    std::cout << "List: ";
    for (List::iterator i=letterList.begin(); i!=letterList.end(); i++)
    {
        std::cout << (*i)->thisLetter << " ";
    }
    std::cout << std::endl;
}

void dump()
{
    std::cout << "========" << std::endl;
    std::cout << "Size: " << letterMap.size() << std::endl;
    for (Map::iterator i=letterMap.begin(); i!=letterMap.end(); i++)
    {
        Letter* l = (*i).second;
        dump(l);
    }
    dumpList();
}

void output()
{
    for (List::iterator i=letterList.begin(); i!=letterList.end(); i++)
    {
        std::cout << (*i)->thisLetter;
    }
    std::cout << std::endl;
}

int main()
{
    std::string prev;
    unsigned prevLength = 0;
    std::string input = "";
    while (std::cin.good())
    {
        //dump();
        prev = input;
        std::cin >> input;
        if (std::cin.fail())
        {
            return 0;
        }
        if (input[0] == '#')
        {
            //dump();
            sortLetters();
            //dump();
            output();
            return 0;
        }

        if (prev == "")
        {
            prevLength = input.length();
            continue;
        }

        unsigned length = input.length();
        if (length > 0)
        {
            compareLetters(prev, prevLength, input, length);
        }

        prevLength = length;
    }
}
