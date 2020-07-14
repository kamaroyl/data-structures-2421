#include "ActorFilterAward.hpp"
#include "ActorFilter.hpp"

ActorFilterAward::ActorFilterAward() {
    this->value = "";
}

bool ActorFilterAward::filter(Actor* actor) {
    if(this->value == "") return false;
    std::size_t found = (actor->getAward()).find(this->value);
    return (found != std::string::npos);
}

void ActorFilterAward::setValue(std::string value) {
    this->value = value;
}
