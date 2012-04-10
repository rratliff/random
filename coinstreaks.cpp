// Robert Ratliff
// coinstreaks.cpp

#include <iostream>
#include <iomanip>
#include <ctime>
#include <gsl/gsl_rng.h>
using namespace std;

const int NUMFLIPS = 100;
const int NUMTRIALS = 1000000;

int main(void) {
    gsl_rng *r;
    int count[NUMFLIPS+1];
    int streaklen, maxstreak;

    r = gsl_rng_alloc(gsl_rng_mt19937);
    gsl_rng_set(r, time(NULL));

    for (int i = 0; i <= NUMFLIPS; i++)
        count[i] = 0;

    for (int j = 0; j < NUMTRIALS; j++) {
        streaklen = 0;
        maxstreak = 0;
        for (int i = 0; i < NUMFLIPS; i++) {
            if (gsl_rng_uniform(r) < 0.5) {
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
    
    gsl_rng_free(r);
    return 0;
}
