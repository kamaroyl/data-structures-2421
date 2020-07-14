#include "PictureFilterDuration.hpp"

PictureFilterDuration::PictureFilterDuration() {
    this->value = 0;
}

void PictureFilterDuration::setValue(std::string value) {
    this->value = (unsigned short) std::stoi(value);
}

bool PictureFilterDuration::filter(Picture* picture) {
    return (this->value == picture->getDuration());
}


