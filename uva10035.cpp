/*
 * UVa Online Judge Judge - Problem 10035
 */

#include <iostream>
#include <sstream>

std::string output(unsigned carry)
{
    switch (carry)
    {
    case 0:
        return "No carry operation.";
    case 1:
        return "1 carry operation.";
    default:
        std::stringstream ss;
        ss << carry << " carry operations.";
        return ss.str();
    }
}

int main()
{
    while (true)
    {
        unsigned long one;
        unsigned long two;
        std::cin >> one;
        std::cin >> two;

        if ((one == 0) && (two == 0))
            return 0;

        unsigned totalCarry = 0;
        unsigned carry = 0;
        do
        {
            unsigned oneDigit = one%10;
            one = one/10;
            unsigned twoDigit = two%10;
            two = two/10;

            if ((oneDigit+twoDigit+carry) >= 10)
            {
                totalCarry++;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

        } while (!((one == 0) && (two == 0)));

        std::cout << output(totalCarry) << std::endl;
    }
    return 0;
}
