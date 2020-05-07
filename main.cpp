#include <iostream>
#include "EpsilonGreedy.h"
#include "UCB1.h"


int main() {
    int NUM_TRIALS[] = {250, 500, 750, 1000, 2000, 5000, 20000};
    EpsilonGreedy e(0.1);
    UCB1 ucb;


    for (int NUM_TRIALS: NUM_TRIALS) {
        cout << "NUM_TRIALS: " << NUM_TRIALS << endl;
        cout << "EPS: ";
        e.experiment(NUM_TRIALS);

        cout << "UCB: ";
        ucb.experiment(NUM_TRIALS);
        cout << endl;

    }

    return 0;
}
