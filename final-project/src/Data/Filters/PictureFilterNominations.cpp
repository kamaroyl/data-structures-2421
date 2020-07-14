#include "PictureFilterNominations.hpp"

PictureFilterNominations::PictureFilterNominations() {
    this->value = 0;
}

void PictureFilterNominations::setValue(std::string value) {
    this->value = (unsigned short) std::stoi(value);
}

bool PictureFilterNominations::filter(Picture* picture) {
    return (this->value == picture->getNominations());
}


