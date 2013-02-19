/**
 * UVa Online Judge - Problem 101
 */

#include <iostream>

const int MAXSIZE = 26;
struct location
{
    int x;
    int y;
};

int blocks[MAXSIZE][MAXSIZE];
int numberOfBlocks;
location locations[MAXSIZE];


void putblock(const int val, const int x, const int y, const bool clear=true)
{
//    std::cout << "PB: " << val << " " << x << " " << y << std::endl;
    if (clear)
        blocks[locations[val].x][locations[val].y] = -1;
    blocks[x][y] = val;
    locations[val].x = x;
    locations[val].y = y;
}

int freeLocation(const int y)
{
    int x=0;
    while (blocks[x][y] != -1)
    {
        x++;
    }
    return x;
}

void returnToOrig(const int val)
{
    int x = freeLocation(val);
    putblock(val, x, val);
}

void results()
{
    for (int y=0; y<numberOfBlocks; y++)
    {
        std::cout << y << ":";

        int x=0;
        while (blocks[x][y] != -1)
        {
            std::cout << " ";
            std::cout << blocks[x][y];
            x++;
        }
        std::cout << std::endl;
    }
}

void dump()
{
    for (int b=0; b<numberOfBlocks; b++)
    {
        std::cout << b << ": (" << locations[b].x
                  << "," << locations[b].y << ")" << std::endl;
    }
    results();
}

void returnAbove(const int block)
{
    int orig = locations[block].x;
    int position = locations[block].y;
    orig++;
    while (blocks[orig][position] != -1)
    {
        returnToOrig(blocks[orig][position]);
        orig++;
    }
}

void process(const std::string verb1, const int a,
             const std::string verb2, const int b)
{
//    std::cout << verb1 << " " << a << " " << verb2 << " " << b << std::endl;
    if ((a < 0) || (a >= numberOfBlocks))
        return;
    if ((b < 0) || (b >= numberOfBlocks))
        return;
    if (locations[a].y == locations[b].y)
        return;

    if (verb1 == "move")
    {
        if (verb2 == "onto")
        {
            returnAbove(a);
            returnAbove(b);
            putblock(a, locations[b].x+1, locations[b].y);
        }
        else if (verb2 == "over")
        {
            returnAbove(a);
            int free = locations[b].x;
            while (blocks[free][locations[b].y] != -1)
            {
                free++;
            }
            putblock(a, free, locations[b].y);
        }
    }
    else if (verb1 == "pile")
    {
        if (verb2 == "onto")
        {
            returnAbove(b);
            int free = freeLocation(locations[b].y);
            int ax = locations[a].x;
            int ay = locations[a].y;
            while (blocks[ax][ay] != -1)
            {
                putblock(blocks[ax][ay], free, locations[b].y);
                ax++;
                free++;
            }
        }
        else if (verb2 == "over")
        {
            int free = freeLocation(locations[b].y);
            int ax = locations[a].x;
            int ay = locations[a].y;
            while (blocks[ax][ay] != -1)
            {
                putblock(blocks[ax][ay], free, locations[b].y);
                ax++;
                free++;
            }
        }
    }
}

void initialize()
{
    for (int x=0; x<MAXSIZE; x++)
    {
        for (int y=0; y<MAXSIZE; y++)
        {
            blocks[x][y] = -1;
        }
    }
    for (int c=0; c<numberOfBlocks; c++)
    {
        putblock(c, 0, c, false);
    }
}

int main()
{
    while (std::cin.good())
    {
        std::cin >> numberOfBlocks;
        initialize();

        if (std::cin.fail())
        {
            return 0;
        }
        while (std::cin.good())
        {
            std::string verb1;
            std::cin >> verb1;
            if (verb1 == "quit")
            {
                break;
            }

            int arg1;
            std::cin >> arg1;
            std::string verb2;
            std::cin >> verb2;
            int arg2;
            std::cin >> arg2;
            process(verb1, arg1, verb2, arg2);
        }

        results();
        return 0;
    }
    return 0;
}
