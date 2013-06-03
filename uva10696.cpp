/*
 * UVa Online Judge - Problem 10696
 */

#include <iostream>

int f91(int n)
{
    if (n <= 100)
        return 91;
    else
        return n-10;
}

int main()
{
    while (true)
    {
        int number;
        std::cin >> number;
        if (number == 0)
            return 0;
        std::cout << "f91(" << number << ") = " << f91(number) << "\n";
    }
    return 0;
}
