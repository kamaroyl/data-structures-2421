#ifndef ACTOR_UTIL_HPP
#define ACTOR_UTIL_HPP
#include "Actor.hpp"

char compareIndex1(Actor *one, Actor *two) {
    if(one->getIndex() < two->getIndex()) return -1;
    if(one->getIndex() == two->getIndex()) return 0;
    return 1; //default greater than
}

char compareYear1(Actor *one, Actor *two) {
    if(one->getYear() < two->getYear()) return -1;
    if(one->getYear() == two->getYear()) return 0;
    return 1; //default greater than
}

char compareAward1(Actor *one, Actor *two) {
    if(one->getAward() < two->getAward()) return -1;
    if(one->getAward() == two->getAward()) return 0;
    return 1;
}

char compareWinner1(Actor *one, Actor *two) {
    if(one->getWinner() < two->getWinner()) return -1;
    if(one->getWinner() == two->getWinner()) return 0;
    return 1;
}

char compareName1(Actor *one, Actor *two) {
    if(one->getName() < two->getName()) return -1;
    if(one->getName() == two->getName()) return 0;
    return 1;
}

char compareFilm1(Actor *one, Actor *two) {
    if(one->getFilm() < two->getFilm()) return -1;
    if(one->getFilm() == two->getFilm()) return 0;
    return 1;
}

char compareIndex(Actor *one, Actor *two, bool reverse) {
    if(reverse) {
        return compareIndex1(two, one);
    } else {
        return compareIndex1(one, two);
    }
}

char compareYear(Actor *one, Actor *two, bool reverse) {
    if(reverse) {
        return compareYear1(two, one);
    } else {
        return compareYear1(one, two);
    }
}

char compareAward(Actor *one, Actor *two, bool reverse) {
    if(reverse) {
        return compareAward1(two, one);
    } else {
        return compareAward1(one, two);
    }
}

char compareWinner(Actor *one, Actor *two, bool reverse) {
    if(reverse) {
        return compareWinner1(two, one);
    } else {
        return compareWinner1(one, two);
    }   
}

char compareName(Actor *one, Actor *two, bool reverse) {
    if(reverse) {
        return compareName1(two, one);
    } else {
        return compareName1(one, two);
    }
}

char compareFilm(Actor *one, Actor *two, bool reverse) {
    if(reverse) {
        return compareFilm1(two, one);
    } else {
        return compareFilm1(one, two);
    }
}
#endif
