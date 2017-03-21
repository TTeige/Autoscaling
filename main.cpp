#include <iostream>
#include "TrivialAutoscale.h"
#include "Simulator.h"

int main() {
    TrivialAutoscale<InputContainer::MetaJob, InputContainer::Resource> alg("test.xml");
    Simulator sim(&alg);
    sim.simulate();
    return 0;
}