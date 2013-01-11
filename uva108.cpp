#include <iostream>

int size;
int array[100][100];

void dumpArray()
{
    for (int y=0; y<size; y++)
    {
        for (int x=0; x<size; x++)
        {
            std::cout << array[x][y] << "  ";
        }
        std::cout << std::endl;
    }
}

int findMaxSum()
{
    int t = 0;
    int pr[100];
    int S = 1<<31, s = 0, k, l, x1 = 0,x2 = 0,y1 = 0,y2 = 0,j;

    for( int z = 0; z < size; z++)
    {
        for(int i = 0; i < size; i++) pr[i] = 0;

        for(int x = z; x < size; x++)
        {
            t = 0;
            s = 1<<31;
            j = 0;
            k = 0; l = 0;
            for(int i = 0; i < size; i++)
            {
                pr[i] = pr[i] + array[x][i];
                t = t + pr[i];
                if( t > s)
                {
                    s = t;
                    k = i;
                    l = j;
                }
                if( t < 0 )
                {
                    t = 0;
                    j = i + 1;
                }
            }
            if( s > S)
            {
                S = s;
                x1 = x;
                y1 = k;
                x2 = z;
                y2 = l;
            }
        }
    }

    return S;
}

int main()
{
    while (std::cin.good())
    {
        std::cin >> size;
        if (std::cin.fail())
        {
            return 0;
        }

        for (int y=0; y<size; y++)
        {
            for (int x=0; x<size; x++)
            {
                std::cin >> array[x][y];
            }
        }
        std::cout << findMaxSum() << std::endl;
    }
    return 0;
}
