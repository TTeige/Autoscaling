//
// Created by tim on 17.03.17.
//

#ifndef MASTERPROJECT_TRIVIALAUTOSCALE_H
#define MASTERPROJECT_TRIVIALAUTOSCALE_H


#include "AutoscalingInterface.h"
#include "InputContainer.h"

class TrivialAutoscale : public AutoscalingInterface {
public:
    TrivialAutoscale(std::string input_file, const char *platform);

    TrivialAutoscale(const char *input_file, const char *platform);

    TrivialAutoscale(InputContainer input, const char *platform);

    void replaceInput(const char *input_file) override;

    void run() override;

private:
    void doScale() override;

    void queryJob(const char *job_id) override;

    void queryResources(const char *resource_id) override;

    void addResource() override;

    void removeResource(const char *resource) override;

private:
    InputContainer mInput;
    InputContainer::MetaJob *mCurrentJob;
    InputContainer::Resource *mCurrentResource;
};

#endif //MASTERPROJECT_TRIVIALAUTOSCALE_H
