//
// Created by tim on 15.03.17.
//

#ifndef MASTERPROJECT_SIMULATOR_H
#define MASTERPROJECT_SIMULATOR_H

#include "AutoscalingInterface.h"
#include "InputContainer.h"
class Simulator {
public:
    Simulator();

    Simulator(InputContainer input);

    Simulator(std::string file);

    Simulator(AutoscalingInterface *alg);

    Simulator(AutoscalingInterface*alg, InputContainer input);

    void setInput(std::string file);

    void setInput(const char *file);

    void setInput(InputContainer input);

    void setAlgorithm(AutoscalingInterface *alg);

    void simulate();

    void simulate(AutoscalingInterface *alg);

private:

    void runSimulation();

private:

    AutoscalingInterface *mAlg = nullptr;
    InputContainer mInput;

};

#endif //MASTERPROJECT_SIMULATOR_H
