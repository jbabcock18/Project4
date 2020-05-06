#include <iostream>
#include "EpsilonGreedy.h"


int main() {
    EpsilonGreedy e(0.1, 1000);
    e.experiment();
    return 0;
}
