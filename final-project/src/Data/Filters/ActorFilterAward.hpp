#ifndef ACTOR_FILTER_AWARD_HPP
#define ACTOR_FILTER_AWARD_HPP
#include "ActorFilter.hpp"
#include <string>
class ActorFilterAward: public ActorFilter {
    private:
        std::string value;

    public:
        ActorFilterAward();
        void setValue(std::string value);
        bool filter(Actor* actor); //exact comparison as awards are short
};
#endif
