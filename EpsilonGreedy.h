//
// Created by Jack Babcock on 5/6/20.
//

#ifndef PROJECT4_EPSILONGREEDY_H
#define PROJECT4_EPSILONGREEDY_H

#include "Bandit.h"
#include <iostream>
#include <vector>

class EpsilonGreedy {
private:
    double epsilon;
    int NUM_TRIALS;
    vector<Bandit*> bandits;
    double BANDIT_PROBABILTIES[3] = {0.2, 0.3, 0.6};
    int sum;
    random_device rd;

public:
    EpsilonGreedy(double eps, int n) {
        epsilon = eps;
        NUM_TRIALS = n;
        for (int i = 0; i < 3; i++) {
            Bandit* b = new Bandit(BANDIT_PROBABILTIES[i]);
            bandits.push_back(b);
        }
        sum = 0;
    }

    void selectBandit() {
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0,1);
        double r =  dis(gen);

        if (r < epsilon) { // EXPLORE
            uniform_int_distribution<> dist(0,2);
            int randIndex = dist(gen);
            bandits[randIndex]->pull();
            if (randIndex == 2)
                sum++;
        }

        else { // EXPLOIT
            int bestBanditIndex = 0;
            double bestProbability = 0;
            for (int i = 0; i < bandits.size(); i++) {
                if (bandits[i]->getSample() > bestProbability) {
                    bestProbability = bandits[i]->getSample();
                    bestBanditIndex = i;
                }
            }
            bandits[bestBanditIndex]->pull();
            if (bestBanditIndex == (bandits.size() - 1)) {
                sum++;
            }
        }
    }

    void experiment() {
        for (int i = 0; i < NUM_TRIALS; i++) {
            selectBandit();;
        }
        double successRate = (double) sum / NUM_TRIALS;
        cout << successRate << endl;
    }


};

#endif //PROJECT4_EPSILONGREEDY_H
