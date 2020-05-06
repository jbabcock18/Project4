//
// Created by Jack Babcock on 5/6/20.
//

#ifndef PROJECT4_EPSILONGREEDY_H
#define PROJECT4_EPSILONGREEDY_H

#include "Bandit.h"
#include <iostream>

class EpsilonGreedy {
private:
    double epsilon;
    int NUM_TRIALS;
public:
    EpsilonGreedy(double eps, int n) {
        epsilon = eps;
        NUM_TRIALS = n;
    }
};

#endif //PROJECT4_EPSILONGREEDY_H
