//
// Created by tim on 13.03.17.
//

#ifndef MASTERPROJECT_INPUTCONTAINER_H
#define MASTERPROJECT_INPUTCONTAINER_H


#include <fstream>
#include <vector>

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
        std::string id;
        int memory;
        //TODO: add resource data
    };

    struct MetaJob {
        int duration;
        std::string id;
        std::vector<Resource> resources;
    };

    std::vector<MetaJob> mJobs;
};


#endif //MASTERPROJECT_INPUTCONTAINER_H
