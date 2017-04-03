//
// Created by tim on 15.03.17.
//

#ifndef MASTERPROJECT_AUTOSCALINGINTERFACE_H
#define MASTERPROJECT_AUTOSCALINGINTERFACE_H

#include <vector>
#include <string>
#include <map>

class AutoscalingInterface {
public:
    AutoscalingInterface(const char *platform);
    //Note: Might force the Autoscaling algorithm to read input in the constructor
    virtual void replaceInput(const char *input_file) = 0;

    virtual void run() = 0;

private:
    //Trivial approach, temporary interface
    virtual void doScale() = 0;

    //The algorithms must be able to query both a job and a resource
    //Can be done by a table lookup after initializing the input
    virtual void queryJob(const char *job_id) = 0;

    virtual void queryResources(const char *resource_id) = 0;

    virtual void addResource() = 0;

    virtual void removeResource(const char *resource) = 0;

public:
    std::string mPlatform;
    std::vector<std::string> mDecicions;

};


#endif //MASTERPROJECT_AUTOSCALINGINTERFACE_H
