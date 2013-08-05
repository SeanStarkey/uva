/*
 * UVa Online Judge - Problem 488
 */

#include <iostream>

int main()
{
    int numberOfWaveforms;

    std::cin >> numberOfWaveforms;

    for (int waveform=0; waveform<numberOfWaveforms; waveform++)
    {
        int amplitude;
        int frequency;

        std::cin >> amplitude;
        std::cin >> frequency;

        if (waveform != 0)
            std::cout << "\n";

        for (int f=0; f<frequency; f++)
        {
            if (f!=0)
                std::cout << "\n";
            for (int a=0; a<amplitude; a++)
            {
                for (int h=0; h<=a; h++)
                {
                    std::cout << (a+1);
                }
                std::cout << "\n";
            }
            for (int a=amplitude-2; a>=0; a--)
            {
                for (int h=0; h<=a; h++)
                {
                    std::cout << (a+1);
                }
                std::cout << "\n";
            }
        }
    }

    return 0;
}
