//
// Created by tim on 17.03.17.
//

#ifndef MASTERPROJECT_TRIVIALAUTOSCALE_H
#define MASTERPROJECT_TRIVIALAUTOSCALE_H


#include "AutoscalingInterface.h"
#include "InputContainer.h"

class TrivialAutoscale : public AutoscalingInterface {
public:

    TrivialAutoscale(const char *input_file);

    TrivialAutoscale(InputContainer input);

    void replaceInput(const char *input_file) override;

private:
    void doScale() override;

    const void queryJob(const char *job_id) override;

    const void queryResources(const char *resource_id) override;

private:
    InputContainer mInput;
};


#endif //MASTERPROJECT_TRIVIALAUTOSCALE_H
