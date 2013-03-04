/*
 * UVa Online Judge - Problem 102
 */
#include <iostream>

int main()
{
    while (std::cin.good())
    {
        unsigned b1;
        unsigned g1;
        unsigned c1;
        unsigned b2;
        unsigned g2;
        unsigned c2;
        unsigned b3;
        unsigned g3;
        unsigned c3;

        std::cin >> b1;
        if (!std::cin.good())
        {
            return 0;
        }
        std::cin >> g1;
        std::cin >> c1;
        std::cin >> b2;
        std::cin >> g2;
        std::cin >> c2;
        std::cin >> b3;
        std::cin >> g3;
        std::cin >> c3;

        unsigned mBCG = b2+b3+c1+c3+g1+g2;
        unsigned mBGC = b2+b3+c1+c2+g1+g3;
        unsigned mCBG = b1+b3+c2+c3+g1+g2;
        unsigned mCGB = b1+b2+c2+c3+g1+g3;
        unsigned mGBC = b1+b3+c1+c2+g2+g3;
        unsigned mGCB = b1+b2+c1+c3+g2+g3;
        if ((mBCG <= mBGC) && (mBCG <= mCBG) && (mBCG <= mCGB) &&
            (mBCG <= mGBC) && (mBCG <= mGCB))
        {
            std::cout << "BCG " << mBCG << std::endl;
            continue;
        }
        if ((mBGC <= mCBG) && (mBGC <= mCGB) && (mBGC <= mGBC) &&
            (mBGC <= mGCB))
        {
            std::cout << "BGC " << mBGC << std::endl;
            continue;
        }
        if ((mCBG <= mCGB) && (mCBG <= mGBC) && (mCBG <= mGCB))
        {
            std::cout << "CBG " << mCBG << std::endl;
            continue;
        }
        if ((mCGB <= mGBC) && (mCGB <= mGCB))
        {
            std::cout << "CGB " << mCGB << std::endl;
            continue;
        }
        if (mGBC <= mGCB)
        {
            std::cout << "GBC " << mGBC << std::endl;
            continue;
        }
        std::cout << "GCB " << mGCB << std::endl;
    }
    return 0;
}
