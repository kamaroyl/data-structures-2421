#ifndef ACTOR_COMPARATOR_HPP
#define ACTOR_COMPARATOR_HPP
#include "../Actor.hpp"
class ActorComparator {
    bool operator()(Actor const &one, Actor const &two);
};
#endif
