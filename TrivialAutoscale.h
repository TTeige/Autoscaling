//
// Created by tim on 17.03.17.
//

#ifndef MASTERPROJECT_TRIVIALAUTOSCALE_H
#define MASTERPROJECT_TRIVIALAUTOSCALE_H


#include "AutoscalingInterface.h"
#include "InputContainer.h"

template<typename Job, typename Res>
class TrivialAutoscale : public AutoscalingInterface {
public:

    TrivialAutoscale(const char *input_file);

    TrivialAutoscale(InputContainer input);

    void replaceInput(const char *input_file) override;

private:
    void doScale() override;

    Job queryJob(const char *job_id) override;

    Res queryResources(const char *resource_id) override;

    void addResource() override;

    void removeResource() override;

private:
    InputContainer mInput;
};

#include "TrivialAutoscale.cpp"

#endif //MASTERPROJECT_TRIVIALAUTOSCALE_H
