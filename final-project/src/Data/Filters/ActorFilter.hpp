#ifndef ACTOR_FILTER_HPP
#define ACTOR_FILTER_HPP
#include "../Actor.hpp"
#include <string>
class ActorFilter {
    public:
        virtual bool filter(Actor* actor);
        virtual void setValue(std::string value);
};
#endif
