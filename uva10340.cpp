/*
 * UVa Online Judge - Problem 10340
 */

#include <iostream>

int main() {
    while (1) {
        std::string s;
        std::string t;
        std::cin >> s;
        if (!std::cin.good()) {
            return 0;
        }
        std::cin >> t;

        bool done = false;
        int s_pos = 0;
        int s_length = s.length();
        int t_pos = 0;
        while (!done) {
            size_t loc = t.find(s[s_pos], t_pos);
            if (loc == std::string::npos) {
                std::cout << "No\n";
                done = true;
            } else {
                s_pos++;
                t_pos = loc+1;
                if (s_pos == s_length) {
                    std::cout << "Yes\n";
                    done = true;
                }
            }
        }
    }
    return 0;
}
