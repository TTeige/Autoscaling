//
// Created by tim on 13.03.17.
//

#ifndef MASTERPROJECT_INPUTCONTAINER_H
#define MASTERPROJECT_INPUTCONTAINER_H


#include <fstream>
#include <vector>
#include <map>


class InputContainer {
public:

    InputContainer();

    InputContainer(std::string file);

    InputContainer(const char *file);

    void addInput(std::string file);

    void addInput(const char *file);

private:
    void parseInputFile(const char *file);

public:
    struct Resource {
        int memory;
        //TODO: add resource data
    };

    struct MetaJob {
        int duration;
        std::string platform;
        float scalability;
        //Array of resources allocated to the job
        std::vector<std::string> resources;
    };

    std::map<std::string, MetaJob> mJobs;
    std::map<std::string, Resource> mResources;
};

#endif //MASTERPROJECT_INPUTCONTAINER_H
