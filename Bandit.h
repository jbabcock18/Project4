//
// Created by Jack Babcock on 5/6/20.
//

#ifndef PROJECT4_BANDIT_H
#define PROJECT4_BANDIT_H
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

class Bandit {
private:
    double probability;
    int a;
    int b;
    double perceivedProbability;

public:
    Bandit(double p) {
        probability = p;
        a = 0; // success
        b = 0; // fail
    }

    bool pull() {
        srand( (unsigned)time( NULL ) );
        rand(); // for some dumb reason this needs to be called once before actually being random.
        double r = (float) rand()/RAND_MAX;
        update(r);
        return r < probability;
    }

    void update(double r) {
        if (r < probability)
            a++;
        else
            b++;
        perceivedProbability = a / (a + b);
    }

    double getSample() {
        return perceivedProbability;
    }



};

#endif //PROJECT4_BANDIT_H
