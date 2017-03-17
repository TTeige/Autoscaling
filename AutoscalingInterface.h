//
// Created by tim on 15.03.17.
//

#ifndef MASTERPROJECT_AUTOSCALINGINTERFACE_H
#define MASTERPROJECT_AUTOSCALINGINTERFACE_H


class AutoscalingInterface {
public:
    //Note: Might force the Autoscaling algorithm to read input in the constructor
    virtual void replaceInput(const char *input_file) = 0;

private:
    //Trivial approach, temporary interface
    virtual void doScale() = 0;

    //The algorithms must be able to query both a job and a resource
    //Might be done by a table lookup after initializing the input
    //Temporary return values. Might change this to be part of the algorithm state for a single iteration.
    virtual const void queryJob(const char *job_id) = 0;

    virtual const void queryResources(const char *resource_id) = 0;

};


#endif //MASTERPROJECT_AUTOSCALINGINTERFACE_H
