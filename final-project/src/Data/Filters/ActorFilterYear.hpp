#ifndef ACTOR_FILTER_YEAR_HPP
#define ACTOR_FILTER_YEAR_HPP
#include "ActorFilter.hpp"
#include <string>
class ActorFilterYear: public ActorFilter {
    private:
        bool equalTo;
        bool greaterThan;
        bool lessThan;
        unsigned short value;

    public:
        ActorFilterYear();
        void setValue(std::string value);
        void setLessThan(bool lessThan);
        void setGreaterThan(bool greaterThan);
        void setEqualTo(bool equalTo);
        bool filter(Actor* actor);
};
#endif 
