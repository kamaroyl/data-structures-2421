#include "PictureFilterGenre1.hpp"

PictureFilterGenre1::PictureFilterGenre1() {
}

void PictureFilterGenre1::setValue(std::string value) {
    this->value = Genre(value);
}

bool PictureFilterGenre1::filter(Picture* picture) {
    return (this->value == picture->getGenre1());
}


