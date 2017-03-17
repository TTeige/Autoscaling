//
// Created by tim on 15.03.17.
//

#include <iostream>
#include "Simulator.h"

Simulator::Simulator() {

}

Simulator::Simulator(InputContainer input) :
        mInput(input) {

}

Simulator::Simulator(std::string file) :
        mInput(InputContainer(file)) {


}

Simulator::Simulator(AutoscalingInterface *alg) :
        mAlg(alg) {

}

Simulator::Simulator(AutoscalingInterface *alg, InputContainer input) :
        mAlg(alg),
        mInput(input) {

}

void Simulator::setInput(std::string file) {
    mInput = InputContainer(file);
}

void Simulator::setInput(const char *file) {
    mInput = InputContainer(file);
}

void Simulator::setInput(InputContainer input) {
    mInput = input;
}

void Simulator::setAlgorithm(AutoscalingInterface *alg) {

    mAlg = alg;

}

void Simulator::simulate() {
    runSimulation();
}

void Simulator::simulate(AutoscalingInterface *alg) {
    mAlg = alg;
    runSimulation();
}

void Simulator::runSimulation() {
    if (mAlg == nullptr) {
        std::cout << "No algorithm specified for the simulation" << std::endl;
        return;
    }

}
