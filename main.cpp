#include <iostream>
#include "InputContainer.h"
#include "TrivialAutoscale.h"
#include "Simulator.h"

int main() {
    InputContainer input("test.xml");
    TrivialAutoscale alg = TrivialAutoscale(input);
    Simulator sim = Simulator(&alg);
    return 0;
}