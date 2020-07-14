#include "ActorComparator.hpp"
#include <iostream>
#include "../../../lib/util/CharUtil.hpp"
#include "../ActorUtil.hpp"

ActorComparator::ActorComparator() {
    this->fields = new Field[this->size];
    this->fields[0].number = 1;
    this->fields[0].func = compareIndex;
    this->fields[0].value = 1;
    this->fields[1].number = 2;
    this->fields[1].func = compareYear;
    this->fields[2].number = 3;
    this->fields[2].func = compareAward;
    this->fields[3].number = 4;
    this->fields[3].func = compareWinner;
    this->fields[4].number = 5;
    this->fields[4].func = compareName;
    this->fields[5].number = 6;
    this->fields[5].func = compareFilm;
}
ActorComparator::~ActorComparator() {
 delete[] this->fields;
}

ActorComparator::ActorComparator(ActorComparator* ac) {
    this->fields = new Field[this->size];
    this->fields[0].number = 1;
    this->fields[0].func = compareIndex;
    this->fields[1].number = 2;
    this->fields[1].func = compareYear;
    this->fields[2].number = 3;
    this->fields[2].func = compareAward;
    this->fields[3].number = 4;
    this->fields[3].func = compareWinner;
    this->fields[4].number = 5;
    this->fields[4].func = compareName;
    this->fields[5].number = 6;
    this->fields[5].func = compareFilm;
  
    char* valueCopy = ac->copyFieldValues();
    for(int i = 0; i < this->size; i++) {
        this->fields[i].value = valueCopy[i];
    }
}

char* ActorComparator::copyFieldValues() {
    char* values = new char[this->size];
    for(int i = 0; i < this->size; i++) {
        values[i] = this->fields[i].value;
    }
    return values;
}

void ActorComparator::setField(unsigned short number, char value) {
    for(unsigned short i = 0; i < this->size; i++) {
        if(this->fields[i].number == number) {
            this->fields[i].value = value;
            break;
        }
    }
    this->insertionSortFields(this->fields, this->size);
}

void ActorComparator::setIndex(char value) {
    this->setField(1, value);
}

void ActorComparator::setYear(char value) {
    this->setField(2, value);
}

void ActorComparator::setAward(char value) {
    this->setField(3, value);
}

void ActorComparator::setWinner(char value) {
    this->setField(4, value);
}

void ActorComparator::setName(char value) {
    this->setField(5, value);
}

void ActorComparator::setFilm(char value) {
    this->setField(6, value);
}

// Clear all current flags out
void ActorComparator::clear() {
    for(int i = 0; i < this->size; i++) {
        this->fields[i].value = 0;
    }
}

char ActorComparator::operator()(Actor *one, Actor *two) {
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

void ActorComparator::insertionSortFields(Field* fields, unsigned short size) {
    for(int i = 1; i < size; i++) {
        Field key = fields[i];
        int j = i - 1;
        while( j >= 0 && abs(fields[j].value) < abs(key.value)) {
            fields[j + 1] = fields[j];
            j--;
        }
        fields[j + 1] = key;
    }
}

