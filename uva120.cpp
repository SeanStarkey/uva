/**
 * UVa Online Judge - Problem 120
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

void flip(const int n, std::vector<int>& vec)
{
    int size = vec.size();
    int numberToSwap = size - n + 1;
    for (int cnt=0; cnt<(numberToSwap+1)/2; cnt++)
    {
        int swap = vec[numberToSwap-cnt-1];
        vec[numberToSwap-cnt-1] = vec[cnt];
        vec[cnt] = swap;
    }
}

void dump(const std::vector<int>& vec)
{
    std::vector<int>::const_iterator iter;
    for (iter=vec.begin(); iter!=vec.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int determineMax(const std::vector<int>& vec, const int cur)
{
    int maxValue = 0;
    int maxPos = 0;
    for (int cnt=0; cnt<cur; cnt++) {
        if (vec[cnt] > maxValue) {
            maxValue = vec[cnt];
            maxPos = cnt;
        }
    }
    return maxPos;
}

int determineFlip(const std::vector<int>& vec, int& cur, const int size)
{
    // dump(vec);
    int search = cur;
    while (true) {
        int ret = determineMax(vec, search);
        // std::cout << "R: " << ret << " S: " << search << std::endl;
        if (cur == 1) {
            // std::cout << "A0" << std::endl;
            cur--;
            return 0;
        }
        else if (ret == 0) {
            // std::cout << "A1" << std::endl;
            cur--;
            return size - cur;
        }
        else if (ret == (search-1)) {
            // std::cout << "A2" << std::endl;
            search--;
            cur--;
        }
        else {
            // std::cout << "A3" << std::endl;
            return size - ret;
        }
    }
}

int doit(std::vector<int> a)
{
    const int size = a.size();
    int cur = a.size();
    int f = 999;
    while (f > 0) {
        f = determineFlip(a, cur, size);
        if (f != 0)
            flip(f, a);
        //std::cout << "F: " << f << " C: " << cur << std::endl;
        std::cout << f << " ";
    }
    //flip(1, a);
    std::cout << std::endl;
    // dump(a);
}

void convert(const std::vector<std::string> tokens, std::vector<int>& returnvec)
{
    std::vector<std::string>::const_iterator i;
    for (i=tokens.begin(); i!=tokens.end(); i++)
    {
        returnvec.push_back(atoi(i->c_str()));
    }
}

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl;
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        copy(std::istream_iterator<std::string>(iss),
             std::istream_iterator<std::string>(),
             std::back_inserter<std::vector<std::string> >(tokens));
        std::vector<int> ints;
        convert(tokens, ints);
        doit(ints);
    }
}

