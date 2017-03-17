//
// Created by tim on 13.03.17.
//

#include "InputContainer.h"
#include <tinyxml2.h>
#include <iostream>

InputContainer::InputContainer() {

}

InputContainer::InputContainer(std::string file) {
    parseInputFile(file.c_str());

}

InputContainer::InputContainer(const char *file) {

    parseInputFile(file);

}

void InputContainer::addInput(std::string file) {
    parseInputFile(file.c_str());
}

void InputContainer::addInput(const char *file) {
    parseInputFile(file);
}

void InputContainer::parseInputFile(const char *file) {
    tinyxml2::XMLDocument in;
    in.LoadFile(file);

    auto *data = in.FirstChildElement("Data");

    for (auto *meta_job = data->FirstChildElement("MetaJob");
         meta_job != nullptr; meta_job = meta_job->NextSiblingElement("MetaJob")) {

        InputContainer::MetaJob job;

        const char *job_name = meta_job->Attribute("id");
        if (job_name == nullptr) {
            std::cout << "Error parsing for the name / id of the meta pipe job" << std::endl;
            exit(0);
        }

        job.id = std::string(job_name);
        meta_job->FirstChildElement("Runtime")->QueryIntText(&job.duration);

        auto *resources = meta_job->FirstChildElement("Resources");
        for (auto *resource = resources->FirstChildElement("Node");
             resource != nullptr; resource = resource->NextSiblingElement("Node")) {

            Resource node;

            const char *r_id = resource->Attribute("id");
            if (r_id == nullptr) {
                std::cout << "Error parsing for the name / id of the resource for " << job.id << std::endl;
                exit(0);
            }
            node.id = std::string(r_id);
            resource->FirstChildElement("Memory")->QueryIntText(&node.memory);
            job.resources.push_back(node);
            std::cout << job.id << std::endl;
        }
        mJobs.push_back(job);
    }
}
