//
// Created by tim on 15.03.17.
//

#include "Simulator.h"

Simulator::Simulator() {

}

Simulator::Simulator(InputContainer input) :
        mInput(input) {

}

Simulator::Simulator(std::string file) :
        mInput(file) {


}

Simulator::Simulator(AutoscalingInterface *alg) :
        mAlg(alg) {

}

Simulator::Simulator(AutoscalingInterface *alg, InputContainer input) :
        mAlg(alg),
        mInput(input) {

}

void Simulator::addInput(std::string file) {
    mInput = InputContainer(file);
}

void Simulator::addInput(const char *file) {
    mInput = InputContainer(file);
}

void Simulator::addAlgorithm(AutoscalingInterface *alg) {

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

}
