# Robert Ratliff
# coinstreaks.py

import random

NUMFLIPS = 100
NUMTRIALS = 1000000

if __name__ == '__main__':
    random.seed()
    count = []
    for i in range(NUMFLIPS+1):
        count.append(0)

    for j in range(NUMTRIALS):
        streaklen = 0
        maxstreak = 0
        for i in range(NUMFLIPS):
            if  random.random() < 0.5:
                streaklen += 1
                if streaklen > maxstreak:
                    maxstreak = streaklen
            else:
                streaklen = 0
        count[maxstreak] += 1
    for i in range(NUMFLIPS+1):
        print '{0:3d} {1:.6f}'.format(i, count[i]/float(NUMTRIALS))

