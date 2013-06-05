/*
 * UVa Online Judge - Problem 579
 */

#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{
    while (1)
    {
        int hour;
        int minute;
        char colon;
        std::cin >> hour;
        std::cin >> colon;
        std::cin >> minute;
        if (hour == 0)
            return 0;
        float minuteAngle = 6 * minute;
        float hourAngle = 30 * (hour%12) + (30 * minute/60.0);
        float difference = fabs(hourAngle - minuteAngle);
        if (difference > 180)
            difference = 360 - difference;
        std::cout << std::fixed << std::setprecision(3) << difference << "\n";
    }
    return 0;
}

