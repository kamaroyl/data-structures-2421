#include "ActorFilterWinner.hpp"
#include "ActorFilter.hpp"


ActorFilterWinner::ActorFilterWinner() {
    this->value = false;
}

bool ActorFilterWinner::s2B(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    if(str == "1") return true;
    std::istringstream ss(str);
    bool b;
    ss >> std::boolalpha >> b;
    return b;
}


void ActorFilterWinner::setValue(std::string value) {
    this->value = this->s2B(value);
}

bool ActorFilterWinner::filter(Actor* actor) {
    return (actor->getWinner() == this->value);
}
