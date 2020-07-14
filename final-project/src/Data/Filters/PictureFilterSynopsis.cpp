#include "PictureFilterSynopsis.hpp"
#include "PictureFilter.hpp"
#include <iostream>
PictureFilterSynopsis::PictureFilterSynopsis() {
    this->value = "";
}

bool PictureFilterSynopsis::filter(Picture* picture) {
    if(this->value == "") return false;
    std::size_t found = (picture->getSynopsis()).find(this->value);
    return (found != std::string::npos);
}

void PictureFilterSynopsis::setValue(std::string value) {
    this->value = value;
}
