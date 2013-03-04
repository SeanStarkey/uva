
#include <iostream>

int main()
{
    while (std::cin.good())
    {
        int v;
        int t;

        std::cin >> v;
        if (std::cin.good())
        {
            std::cin >> t;

            std::cout << v * t * 2 << std::endl;
        }
    }
    return 0;
}
