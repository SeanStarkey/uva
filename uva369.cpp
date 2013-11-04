/*
 * UVa Online Judge - Problem 369
 */

#include <iostream>

int main() {
    while (1) {
        unsigned long n;
        unsigned long m;
        std::cin >> n;
        std::cin >> m;
        if ((n == 0) && (m == 0))
            return 0;

        unsigned long nm = n - m;

        unsigned long long c = 1;
        if (nm > m) {
            for (int x = n, y = 1; x > nm; x--, y++) {
                c *= x;
                c /= y;
            }
        } else {
            for (int x = n, y = 1; x > m; x--, y++) {
                c *= x;
                c /= y;
            }
        }

        std::cout << n << " things taken " << m << " at a time is "
                  << c << " exactly.\n";
    }
    return 0;
}
