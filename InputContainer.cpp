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

        const char *job_id = meta_job->Attribute("id");
        const char *type = meta_job->Attribute("platform");
        if (job_id == nullptr || type == nullptr) {
            std::cout << "Error parsing for the id / type of the meta pipe job" << std::endl;
            exit(0);
        }


        meta_job->FirstChildElement("Runtime")->QueryIntText(&job.duration);
        meta_job->FirstChildElement("Scalability")->QueryFloatText(&job.scalability);

        auto *resources = meta_job->FirstChildElement("Resources");
        for (auto *resource = resources->FirstChildElement("Node");
             resource != nullptr; resource = resource->NextSiblingElement("Node")) {

            InputContainer::Resource node;

            const char *r_id = resource->Attribute("id");
            if (r_id == nullptr) {
                std::cout << "Error parsing for the name / id of the resource for " << job_id << std::endl;
                exit(0);
            }

            resource->FirstChildElement("Memory")->QueryIntText(&node.memory);

            job.resources.push_back(std::string(r_id));

            mResources.insert(std::pair<std::string, InputContainer::Resource>(std::string(r_id), node));
        }
        std::cout << "Inserted job: " << job_id << std::endl;
        mJobs.insert(std::pair<std::string, InputContainer::MetaJob>(job_id, job));
    }
}
