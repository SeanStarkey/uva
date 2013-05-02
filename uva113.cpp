/*
 * UVa Online Judge - Problem 113 - Power of Cryptography
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <math.h>

class BigUnsigned
{
public:
    std::vector<short> digits;

    BigUnsigned(unsigned initial);
    BigUnsigned(std::string initial);

    const BigUnsigned operator*(const unsigned &);
    bool operator==(const BigUnsigned &);
    int equals(const BigUnsigned &);
    double toDouble();
    std::string toString();
};

BigUnsigned::BigUnsigned(unsigned initial)
{
    while (initial > 0)
    {
        int digit = initial%10;
        digits.push_back(digit);
        initial = initial/10;
    }
}

BigUnsigned::BigUnsigned(std::string initial)
{
    for (int i=initial.length()-1; i>=0; i--)
    {
        digits.push_back(initial[i] - '0');
    }
}


const BigUnsigned BigUnsigned::operator*(const unsigned &factor)
{
    int carry = 0;
    int size = digits.size();
    for (int i=0; i<size; i++)
    {
        unsigned product = factor * digits[i] + carry;
        digits[i] = product%10;
        carry = product/10;
    }
    while (carry > 0)
    {
        digits.push_back(carry%10);
        carry = carry/10;
    }
    return *this;
}

bool BigUnsigned::operator==(const BigUnsigned & rhs)
{
    if (digits.size() != rhs.digits.size())
        return false;
    for (int i=0; i<digits.size(); i++)
        if (digits[i] != rhs.digits[i])
            return false;
    return true;
}

int BigUnsigned::equals(const BigUnsigned & rhs)
{
    if (digits.size() < rhs.digits.size())
        return -1;
    if (digits.size() > rhs.digits.size())
        return 1;
    for (int i=(digits.size()-1); i>=0; i--)
    {
        if (digits[i] < rhs.digits[i])
            return -1;
        if (digits[i] > rhs.digits[i])
            return 1;
    }
    return 0;
}

double BigUnsigned::toDouble()
{
    double result = 0;
    double level = 1.0;
    for (int i=(digits.size()-1); i>=0; i--)
    {
        result *= 10.0;
        result += level * digits[i];
    }
    return result;
}

std::string BigUnsigned::toString()
{
    std::stringstream out;

    for (int i=(digits.size()-1); i>=0; i--)
    {
        out << digits[i] << ".";
    }
    return out.str();
}

int main()
{
    while (true)
    {
        unsigned n;
        std::string pString;

        std::cin >> n;
        if (!std::cin.good())
            return 0;
        std::cin >> pString;

        BigUnsigned p(pString);

        int k = floor(pow(p.toDouble(), 1.0/n) + 0.5);

        // int k=2;
        // int kold=2;
        // int check;
        // while (true)
        // {
        //     // std::cout << "K: " << k << std::endl;
        //     BigUnsigned result(1);
        //     for (int i=0; i<n; i++)
        //         result = result * k;
        //     check = p.equals(result);
        //     if (check == 0)
        //         break;
        //     if (check == 1)
        //     {
        //         kold = k;
        //         k = k*10;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // if (check != 0)
        // {
        //     int klow = kold;
        //     int khigh = k;
        //     k = (klow+khigh)/2;
        //     while (true)
        //     {
        //         // std::cout << "K: " << klow << " " << k << " " << khigh << std::endl;
        //         BigUnsigned result(1);
        //         for (int i=0; i<n; i++)
        //             result = result * k;
        //         check = p.equals(result);
        //         // std::cout << "R: " << result.toString() << std::endl;
        //         // std::cout << "C: " << check << std::endl;
        //         if (check == 0)
        //             break;
        //         if (check == -1)
        //             khigh = k;
        //         if (check == 1)
        //             klow = k;
        //         k = (klow+khigh)/2;
        //     }
        // }
        std::cout << k << std::endl;
    }
    return 0;
}
