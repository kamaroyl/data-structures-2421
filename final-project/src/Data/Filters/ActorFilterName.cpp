#include "ActorFilterName.hpp"
#include "ActorFilter.hpp"
#include <iostream>
ActorFilterName::ActorFilterName() {
    this->value = "";
}

bool ActorFilterName::filter(Actor* actor) {
    if(this->value == "") return false;
    std::size_t found = (actor->getName()).find(this->value);
    return (found != std::string::npos);
}

void ActorFilterName::setValue(std::string value) {
    this->value = value;
}
