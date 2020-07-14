#ifndef ACTOR_FILTER_NAME_HPP
#define ACTOR_FILTER_NAME_HPP
#include <string>
#include "../Actor.hpp"
#include "ActorFilter.hpp"
class ActorFilterName: public ActorFilter {
    private:
        std::string value;

    public:
        ActorFilterName();
        void setValue(std::string value);
        bool filter(Actor* actor); //Partial Comparison
};
#endif
