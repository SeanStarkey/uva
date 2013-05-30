/**
 * UVa Online Judge - Proble 10783
 */

#include <iostream>

int main()
{
    int testcases;
    std::cin >> testcases;

    for (int i=0; i<testcases; i++)
    {
        int a;
        int b;
        std::cin >> a;
        std::cin >> b;

        int sum=0;
        for (int j=a; j<=b; j++)
        {
            if (j%2 == 1)
            {
                sum += j;
            }
        }
        std::cout << "Case " << (i+1) << ": " << sum << std::endl;
    }

    return 0;
}
