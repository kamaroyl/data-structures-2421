#include "PictureFilterMetacritic.hpp"

PictureFilterMetacritic::PictureFilterMetacritic() {
    this->value = 0;
}

void PictureFilterMetacritic::setValue(std::string value) {
    this->value = (unsigned short) std::stoi(value);
}

bool PictureFilterMetacritic::filter(Picture* picture) {
    return (this->value == picture->getMetacritic());
}


