#include "PictureFilterGenre2.hpp"

PictureFilterGenre2::PictureFilterGenre2() {
}

void PictureFilterGenre2::setValue(std::string value) {
    this->value = Genre(value);
}

bool PictureFilterGenre2::filter(Picture* picture) {
    return (this->value == picture->getGenre1());
}


