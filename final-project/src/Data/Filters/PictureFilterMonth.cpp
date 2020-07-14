#include "PictureFilterMonth.hpp"

PictureFilterMonth::PictureFilterMonth() {
}

void PictureFilterMonth::setValue(std::string value) {
    this->value = Month(value);
}

bool PictureFilterMonth::filter(Picture* picture) {
    return (this->value == picture->getRelease());
}


