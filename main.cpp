#include <iostream>
#include "EpsilonGreedy.h"
#include "UCB1.h"


int main() {
    int NUM_TRIALS = 2000;
    EpsilonGreedy e(0.05);
    e.experiment(NUM_TRIALS);
    UCB1 ucb;
    ucb.experiment(NUM_TRIALS);
    return 0;
}
