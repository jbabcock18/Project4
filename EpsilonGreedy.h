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
    vector<Bandit*> bandits;
    double BANDIT_PROBABILTIES[3] = {0.2, 0.3, 0.6};
    int sum;
    int totalTrials = 0;
    random_device rd;

public:
    EpsilonGreedy(double eps) {
        epsilon = eps;
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
            if (bestBanditIndex == bandits.size()-1) {
                sum++;
            }
        }
    }

    void experiment(int NUM_TRIALS) {
        totalTrials += NUM_TRIALS;
        for (int i = 0; i < NUM_TRIALS; i++) {
            selectBandit();;
        }
        double successRate = (double) sum / totalTrials;
        cout << successRate * 100 << "%" << endl;
    }


};

#endif //PROJECT4_EPSILONGREEDY_H
