//
// Created by tim on 17.03.17.
//

#include "TrivialAutoscale.h"

TrivialAutoscale::TrivialAutoscale(const char *input_file) {
    mInput = InputContainer(input_file);
}

TrivialAutoscale::TrivialAutoscale(InputContainer input) {
    mInput = input;
}

void TrivialAutoscale::replaceInput(const char *input_file) {
    mInput = InputContainer(input_file);
}

void TrivialAutoscale::doScale() {

}

const void TrivialAutoscale::queryJob(const char *job_id) {
    return;
}

const void TrivialAutoscale::queryResources(const char *resource_id) {
    return;
}
