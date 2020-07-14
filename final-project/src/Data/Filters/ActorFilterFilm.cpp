#include "ActorFilterFilm.hpp"
#include "ActorFilter.hpp"

ActorFilterFilm::ActorFilterFilm() {
    this->value = "";
}

bool ActorFilterFilm::filter(Actor* actor) {
    if(this->value == "") return false;
    std::size_t found = (actor->getFilm()).find(this->value);
    return (found != std::string::npos);
}

void ActorFilterFilm::setValue(std::string value) {
    this->value = value;
}
