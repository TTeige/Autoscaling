//
// Created by tim on 13.03.17.
//

#include "InputContainer.h"
#include <tinyxml2.h>

InputContainer::InputContainer(std::string file) {
    tinyxml2::XMLDocument in;
    in.LoadFile(file.c_str());

    auto *data = in.FirstChildElement("data");

    for (auto *meta_job = data->FirstChildElement("MetaJob");
         meta_job != nullptr; meta_job = data->NextSiblingElement("MetaJob")) {
        InputContainer::MetaJob job;

    }
}
