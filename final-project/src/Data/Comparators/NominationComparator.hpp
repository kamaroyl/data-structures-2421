#ifndef NOMINATION_COMPARATOR_HPP
#define NOMINATION_COMPARATOR_HPP
#include "../Nomination.hpp"
class NominationComparator {
    bool operator()(Nomination const &one, Nomination const &two);
};
#endif
