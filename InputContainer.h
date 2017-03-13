//
// Created by tim on 13.03.17.
//

#ifndef MASTERPROJECT_INPUTCONTAINER_H
#define MASTERPROJECT_INPUTCONTAINER_H


#include <fstream>
#include <vector>

class InputContainer {
public:

    InputContainer(std::string file);

public:
    struct Resource {
        std::string id;
        //TODO: add resource data
    };

    struct MetaJob {
        int duration;
        std::string id;
        std::vector<Resource> mResources;
    };

    std::vector<MetaJob> mJobs;
};


#endif //MASTERPROJECT_INPUTCONTAINER_H
