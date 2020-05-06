//
// Created by Jack Babcock on 5/6/20.
//

#ifndef PROJECT4_BANDIT_H
#define PROJECT4_BANDIT_H
#include <ctime>
#include <random>
#include <cstdlib>
#include <iostream>

using namespace std;

class Bandit {
private:
    double probability;
    int a;
    int b;
    random_device rd;
    double averageReward;

public:
    Bandit(double p) {
        probability = p;
        a = 1; // success
        b = 1; // fail
        averageReward = 0;
    }

    bool pull() {
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0,1);
        double r =  dis(gen);
        update(r);
        return r < probability;
    }

    void update(double r) {
        if (r < probability)
            a++;
        else
            b++;
        int n = a + b;
        double newAverageReward = (double) a /  (a+b);
        averageReward = newAverageReward;
    }

    double getSample() {
        return averageReward;
    }



};

#endif //PROJECT4_BANDIT_H
