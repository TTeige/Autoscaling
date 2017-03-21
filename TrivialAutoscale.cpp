//
// Created by tim on 17.03.17.
//

#include <iostream>
#include "TrivialAutoscale.h"

template<typename Job, typename Res>
TrivialAutoscale::TrivialAutoscale(const char *input_file) {
    mInput = InputContainer(input_file);
}

template<typename Job, typename Res>
TrivialAutoscale::TrivialAutoscale(InputContainer input) {
    mInput = input;
}

template<typename Job, typename Res>
void TrivialAutoscale::replaceInput(const char *input_file) {
    mInput = InputContainer(input_file);
}

template<typename Job, typename Res>
void TrivialAutoscale::doScale() {

}

template<typename Job, typename Res>
Job TrivialAutoscale::queryJob(const char *job_id) {

    auto job = mInput.mJobs.find(std::string(job_id));

    if (job != mInput.mJobs.end()) {
        InputContainer::MetaJob meta_job = job->second;
    }
    return;
}

template<typename Job, typename Res>
Res TrivialAutoscale::queryResources(const char *resource_id) {
    return;
}

template<typename Job, typename Res>
void TrivialAutoscale::addResource() {

}

template<typename Job, typename Res>
void TrivialAutoscale::removeResource() {

}
