//
// Created by tim on 17.03.17.
//

#include <iostream>
#include "TrivialAutoscale.h"

TrivialAutoscale::TrivialAutoscale(std::string input_file, const char *platform) : AutoscalingInterface (platform){
    mInput = InputContainer(input_file);
}

TrivialAutoscale::TrivialAutoscale(const char *input_file, const char *platform) : AutoscalingInterface (platform) {
    mInput = InputContainer(input_file);
}

TrivialAutoscale::TrivialAutoscale(InputContainer input, const char *platform) : AutoscalingInterface (platform) {
    mInput = input;
}

void TrivialAutoscale::replaceInput(const char *input_file) {
    mInput = InputContainer(input_file);
}

void TrivialAutoscale::doScale() {

}

void TrivialAutoscale::queryJob(const char *job_id) {

    auto job_iter = mInput.mJobs.find(std::string(job_id));

    if (job_iter != mInput.mJobs.end()) {
        mCurrentJob = &job_iter->second;
    }
}

void TrivialAutoscale::queryResources(const char *resource_id) {
    auto res_iter = mInput.mResources.find(std::string(resource_id));

    if (res_iter != mInput.mResources.end()) {
        mCurrentResource = &res_iter->second;
    }
}

void TrivialAutoscale::addResource() {

    //Query the specific API for a new resource and link it to the job

}

void TrivialAutoscale::removeResource(const char *resource) {

    //Request a shutdown of a resource to remove it from the allocated resources

}

void TrivialAutoscale::run() {

}
