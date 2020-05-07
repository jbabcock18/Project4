//
// Created by Jack Babcock on 5/6/20.
//
#include "Bandit.h"

#ifndef PROJECT4_UCB1_H
#define PROJECT4_UCB1_H

#include <vector>
#include <iostream>
#include "math.h"

class UCB1 {
private:
    vector<Bandit*> bandits;
    double BANDIT_PROBABILTIES[3] = {0.2, 0.3, 0.6};
    int pulls[3]  = {1,1,1}; // value formal doesn't work if set to 0
    double values[3] = {0,0,0};
    int sum;
    int totalTrials = 0;
public:
    UCB1() {
        for (int i = 0; i < 3; i++) {
            Bandit* b = new Bandit(BANDIT_PROBABILTIES[i]);
            bandits.push_back(b);
            values[i] = calculateValue(i);
        }
        sum = 0;
    }

    double calculateValue(int i) {
        int totalPulls  = 0;
        for (int n: pulls) {
            totalPulls += n;
        }
        double mean = bandits[i]->getSample();
        double ucb  = sqrt(
                (2 * log10(totalPulls)) /
                pulls[i]
                );
        return  mean + ucb;
    }

    void update(int i) {
        pulls[i]++;
        values[i] = calculateValue(i);
    }

    void selectBandit() {
        int bestBanditIndex = 0;
        double bestBanditValue = 0;
        for (int i = 0; i < bandits.size(); i++) {
            if (values[i] > bestBanditValue) {
                bestBanditValue = values[i];
                bestBanditIndex = i;
            }
        }
        bandits[bestBanditIndex]->pull();
        update(bestBanditIndex);
        if (bestBanditIndex ==  bandits.size() -1)
            sum++;
    }

    void experiment(int NUM_TRIALS) {
        totalTrials += NUM_TRIALS;
        for (int i = 0; i < NUM_TRIALS; i++) {
            selectBandit();
        }
        double successRate = (double) sum / totalTrials;
        cout << successRate * 100 << "%" << endl;
    }
};

#endif //PROJECT4_UCB1_H
