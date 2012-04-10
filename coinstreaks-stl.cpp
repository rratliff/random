// Robert Ratliff
// coinstreaks-stl.cpp

#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;

const int NUMFLIPS = 100;
const int NUMTRIALS = 1000000;

mt19937 rng;
uniform_real_distribution<> dis(0,1); // Uniform distribution over [0,1)

int main(void) {
    int count[NUMFLIPS+1];
    int streaklen, maxstreak;

    rng.seed(time(NULL));

    for (int i = 0; i <= NUMFLIPS; i++)
        count[i] = 0;

    for (int j = 0; j < NUMTRIALS; j++) {
        streaklen = 0;
        maxstreak = 0;
        for (int i = 0; i < NUMFLIPS; i++) {
            if (dis(rng) < 0.5) {
                streaklen ++;
                if (streaklen > maxstreak)
                    maxstreak = streaklen;
            } else {
                streaklen = 0;
            }
        }
        count[maxstreak]++;
    }

    for (int i = 0; i <= NUMFLIPS; i++) {
        cout << setw(3) << right << i << " ";
        cout << fixed << setprecision(6);
        cout << count[i]/static_cast<double>(NUMTRIALS);
        cout << endl;
    }
    
    return 0;
}
