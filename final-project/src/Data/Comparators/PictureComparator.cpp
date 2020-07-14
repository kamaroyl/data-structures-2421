#include "PictureComparator.hpp"
#include "../../../lib/util/CharUtil.hpp"
#include "../PictureUtil.hpp"

PictureComparator::PictureComparator() {
    this->fields = new PictureField[this->size];
    this->fields[0].number = 1;
    this->fields[0].func = compareIndex;
    this->fields[0].value = 1;
    this->fields[1].number = 2;
    this->fields[1].func = compareName;
    this->fields[2].number = 3;
    this->fields[2].func = compareYear;
    this->fields[3].number = 4;
    this->fields[3].func = compareNominations;
    this->fields[4].number = 5;
    this->fields[4].func = compareRating;
    this->fields[5].number = 6;
    this->fields[5].func = compareDuration;
    this->fields[6].number = 7;
    this->fields[6].func = compareGenre1;
    this->fields[7].number = 8;
    this->fields[7].func = compareGenre2;
    this->fields[8].number = 9;
    this->fields[8].func = compareRelease;
    this->fields[9].number = 10;
    this->fields[9].func = compareMetacritic;
    this->fields[10].number = 11;
    this->fields[10].func = compareSynopsis;
}

PictureComparator::PictureComparator(PictureComparator* pc) {
    this->fields = new PictureField[this->size];
    this->fields[0].number = 1;
    this->fields[0].func = compareIndex;
    this->fields[1].number = 2;
    this->fields[1].func = compareName;
    this->fields[2].number = 3;
    this->fields[2].func = compareYear;
    this->fields[3].number = 4;
    this->fields[3].func = compareNominations;
    this->fields[4].number = 5;
    this->fields[4].func = compareRating;
    this->fields[5].number = 6;
    this->fields[5].func = compareDuration;
    this->fields[6].number = 7;
    this->fields[6].func = compareGenre1;
    this->fields[7].number = 8;
    this->fields[7].func = compareGenre2;
    this->fields[8].number = 9;
    this->fields[8].func = compareRelease;
    this->fields[9].number = 10;
    this->fields[9].func = compareMetacritic;
    this->fields[10].number = 11;
    this->fields[10].func = compareSynopsis;
    char* values = pc->copyFieldValues();
    for(int i = 0; i < this->size; i++) {
        this->fields[i].value = values[i];
    }
}

PictureComparator::~PictureComparator(){
    delete[] this->fields;
}

char* PictureComparator::copyFieldValues() {
    char* values = new char[this->size];
    for(int i = 0; i < this->size; i++) {
        values[i] = this->fields[i].value;
    }
    return values;
}

//Constant size will not grow, O(1) and the number of elements is small
void PictureComparator::setField(unsigned short number, char value) {
    for(unsigned short i = 0; i < this->size; i++) {
        if(this->fields[i].number == number) {
            this->fields[i].value = value;
            break;
        }
    }
    this->insertionSortFields(this->fields, this->size);
}

void PictureComparator::setIndex(char value) {
    this->setField(1, value);
}

void PictureComparator::setName(char value) {
    this->setField(2, value);
}

void PictureComparator::setYear(char value) {
    this->setField(3, value);
}

void PictureComparator::setNominations(char value) {
    this->setField(4, value);
}
void PictureComparator::setRating(char value) {
    this->setField(5, value);
}
void PictureComparator::setDuration(char value) {
    this->setField(6, value);
}
void PictureComparator::setGenre1(char value) {
    this->setField(7, value);
}

void PictureComparator::setGenre2(char value) {
    this->setField(8, value);
}

void PictureComparator::setRelease(char value) {
    this->setField(9, value);
}

void PictureComparator::setMetacritic(char value) {
    this->setField(10, value);
}

void PictureComparator::setSynopsis(char value) {
    this->setField(11, value);
}

void PictureComparator::clear() {
    for(int i = 0; i < this->size; i++) {
        this->fields[i].value = 0;
    }
}

char PictureComparator::operator()(Picture *one, Picture *two) {
    for(unsigned short i = 0; i < this->size; i++) {
        if(this->fields[i].value != 0) {
            bool reverse = (this->fields[i].value < 0);
            char tmp = this->fields[i].func(one, two, reverse);
            if(tmp != 0) return tmp;
        } else {
            break;
        }
    }
    return 0;
}

void PictureComparator::insertionSortFields(PictureField* fields, unsigned short size) {
    for(int i = 1; i < size; i++) {
        PictureField key = fields[i];
        int j = i - 1;
        while(j >= 0 && abs(fields[j].value) < abs(key.value)) {
            fields[j + 1] = fields[j];
            j--;
        }
        fields[j + 1] = key;
    }
}
