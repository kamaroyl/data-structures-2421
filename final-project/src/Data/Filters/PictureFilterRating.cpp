#include "PictureFilterRating.hpp"

PictureFilterRating::PictureFilterRating() {
    this->value = 0;
}

void PictureFilterRating::setValue(std::string value) {
    this->value = std::stof(value);
}

bool PictureFilterRating::filter(Picture* picture) {
    return (this->value == picture->getRating());
}


