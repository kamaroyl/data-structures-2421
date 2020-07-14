#include "PictureFilterName.hpp"
#include "PictureFilter.hpp"
#include <iostream>
PictureFilterName::PictureFilterName() {
    this->value = "";
}

bool PictureFilterName::filter(Picture* picture) {
    if(this->value == "") return false;
    std::size_t found = (picture->getName()).find(this->value);
    return (found != std::string::npos);
}

void PictureFilterName::setValue(std::string value) {
    this->value = value;
}
