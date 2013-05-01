/*
 * UVa Online Judge - Problem 10189
 */

#include <iostream>

int xsize;
int ysize;
int field[100][100];

int main()
{
    unsigned fieldNumber = 1;
    while (true)
    {
        std::cin >> xsize;
        std::cin >> ysize;

        if ((xsize == 0) && (ysize == 0))
            return 0;

        char c;
        for (int x=0; x<xsize; x++)
            for (int y=0; y<ysize; y++)
            {
                std::cin >> c;
                if (c == '*')
                    field[x][y] = -1;
                else
                    field[x][y] = 0;
            }

        for (int x=0; x<xsize; x++)
            for (int y=0; y<ysize; y++)
                if (field[x][y] != -1)
                    for (int xd=-1; xd<=1; xd++)
                        for (int yd=-1; yd<=1; yd++)
                            if (!(x+xd < 0) && !(x+xd >= xsize) &&
                                !(y+yd < 0) && !(y+yd >= ysize))
                                if (field[x+xd][y+yd] == -1)
                                    field[x][y]++;

        if (fieldNumber > 1)
            std::cout << std::endl;
        std::cout << "Field #" << fieldNumber++ << ":" << std::endl;
        for (int x=0; x<xsize; x++)
        {
            for (int y=0; y<ysize; y++)
            {
                if (field[x][y] == -1)
                    std::cout << "*";
                else
                    std::cout << field[x][y];
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
