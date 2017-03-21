#include <iostream>
#include "TrivialAutoscale.h"
#include "Simulator.h"

int main() {
    TrivialAutoscale alg("test.xml");
    Simulator sim(&alg);
    sim.simulate();
    return 0;
}