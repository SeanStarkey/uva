#include <iostream>

int main() {
    while (std::cin.good()) {
        unsigned n;
        unsigned k;
        std::cin >> n;
        if (!std::cin.good()) {
            return 0;
        }
        std::cin >> k;

        unsigned c = n;
        unsigned b = n;
        do {
            unsigned s = b / k;
            b = b - s*k;
            c += s;
            b += s;
        } while (b >= k);
        std::cout << c << "\n";
    }
    return 0;
}
