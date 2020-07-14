#include "ActorFilterYear.hpp"
#include "ActorFilter.hpp"
#include <string>

ActorFilterYear::ActorFilterYear() {
    this->equalTo = false;
    this->lessThan = false;
    this->greaterThan = false;
    this->value = 0;
}

void ActorFilterYear::setValue(std::string value) {
    this->value = (unsigned short) std::stoi(value);
}

void ActorFilterYear::setLessThan(bool lessThan) {
    this->lessThan = lessThan;
}

void ActorFilterYear::setGreaterThan(bool greaterThan) {
    this->greaterThan = greaterThan;
}

void ActorFilterYear::setEqualTo(bool equalTo) {
    this->equalTo = equalTo;
}

bool ActorFilterYear::filter(Actor* actor) {
    bool result = true;
    this->equalTo = true;
    if(this->equalTo) {
        result = (this->value == actor->getYear());
    }
    if(this->greaterThan) {
        result = result || (actor->getYear() > this->value);
    }
    if(this->lessThan) {
        result = result || (actor->getYear() < this->value);
    }
    return result;
}

