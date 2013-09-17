/*
 * UVa Online Judge - Problem 382
 */

#include <iostream>
#include <iomanip>

int main() {
    std::cout << "PERFECTION OUTPUT\n";
    while (1) {
        int n;
        std::cin >> n;
        if (n == 0) {
            std::cout << "END OF OUTPUT\n";
            return 0;
        }
        int sum = 0;
        for (int f=1; f<=n/2; f++) {
            if (n%f == 0) {
                sum += f;
            }
        }
        std::cout << std::setw(5) << n;
        std::cout << "  ";
        if (sum < n) {
            std::cout << "DEFICIENT\n";
        } else if (sum > n) {
            std::cout << "ABUNDANT\n";
        } else {
            std::cout << "PERFECT\n";
        }
    }
    return 0;
}
