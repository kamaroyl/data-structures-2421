#ifndef ACTOR_FILTER_WINNER_HPP
#define ACTOR_FILTER_WINNER_HPP
#include "../Actor.hpp"
#include "ActorFilter.hpp"
class ActorFilterWinner: public ActorFilter {
    private:
        bool value;
        bool s2B(std::string value);
    
    public:
        ActorFilterWinner();
        void setValue(std::string value);
        bool filter(Actor* actor);
};
#endif 
