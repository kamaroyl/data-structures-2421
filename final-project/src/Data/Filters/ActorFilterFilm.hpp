#ifndef ACTOR_FILTER_FILM_HPP
#define ACTOR_FILTER_FILM_HPP
#include "ActorFilter.hpp"

class ActorFilterFilm: public ActorFilter {
    private:
        std::string value;

    public:
        ActorFilterFilm();
        void setValue(std::string value);
        bool filter(Actor* actor); //partial comparison
};
#endif
