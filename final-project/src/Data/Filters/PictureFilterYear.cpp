#include "PictureFilterYear.hpp"
#include "PictureFilter.hpp"

PictureFilterYear::PictureFilterYear() {
    this->equalTo = false;
    this->lessThan = false;
    this->greaterThan = false;
    this->value = 0;
}

void PictureFilterYear::setValue(std::string value) {
    this->value = (unsigned short) std::stoi(value);
}

void PictureFilterYear::setEqualTo(bool equalTo) {
    this->equalTo = equalTo;
}

void PictureFilterYear::setGreaterThan(bool greaterThan) {
    this->greaterThan = greaterThan;
}

void PictureFilterYear::setLessThan(bool lessThan) {
    this->lessThan = lessThan;
}

bool PictureFilterYear::filter(Picture* picture) {
    bool result = false;
    this->equalTo = true;
    if(this->equalTo) {
        result = (this->value == picture->getYear());
    }
    if(this->greaterThan) {
        result = result || (picture->getYear() > this->value);
    }
    if(this->lessThan) {
        result = result || (picture->getYear() < this->value);
    }
    return result;
}
