/*
 * UVa Online Judge - Problem 424
 */

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>

class VeryLongInteger
{
private:
    std::vector<int> digits;

public:
    VeryLongInteger(std::string strValue);
    void add(VeryLongInteger vli);
    std::string toString();
};

VeryLongInteger::VeryLongInteger(std::string strValue)
{
    int length = strValue.length();
    std::stack<int> tempStack;
    for (int i=0; i<length; i++) {
        tempStack.push(strValue[i]-'0');
    }
    for (int i=0; i<length; i++) {
        digits.push_back(tempStack.top());
        tempStack.pop();
    }
}

void VeryLongInteger::add(VeryLongInteger vli)
{
    int minLength = std::min(digits.size(), vli.digits.size());
    int maxLength = std::max(digits.size(), vli.digits.size());
    std::vector<int> oldDigits = digits;
    digits.clear();

    int carry = 0;
    for (int i=0; i<minLength; i++)
    {
        int sum = oldDigits[i] + vli.digits[i] + carry;
        carry = sum/10;
        sum = sum%10;
        digits.push_back(sum);
    }
    if (oldDigits.size() > vli.digits.size())
    {
        for (int i=minLength; i<maxLength; i++)
        {
            int sum = oldDigits[i] + carry;
            carry = sum/10;
            sum = sum%10;
            digits.push_back(sum);
        }
    }
    else
    {
        for (int i=minLength; i<maxLength; i++)
        {
            int sum = vli.digits[i] + carry;
            carry = sum/10;
            sum = sum%10;
            digits.push_back(sum);
        }
    }
    if (carry == 1)
    {
        digits.push_back(1);
    }
}

std::string VeryLongInteger::toString()
{
    std::stringstream result;

    for (int i=digits.size()-1; i>=0; i--)
        result << digits[i];
    return result.str();
}

int main ()
{
    VeryLongInteger sum("0");
    while (1)
    {
        std::string number;
        std::cin >> number;
        if (number == "0")
        {
            std::cout << sum.toString() << std::endl;
            return 0;
        }

        VeryLongInteger a(number);
        sum.add(a);
    }
}
