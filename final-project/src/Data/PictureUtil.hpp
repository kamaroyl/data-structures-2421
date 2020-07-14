#ifndef PICTURE_UTIL_HPP
#define PICTURE_UTIL_HPP
#include "Picture.hpp"

char compareIndex1(Picture *one, Picture *two) {
    if(one->getIndex() < two->getIndex()) return -1;
    if(one->getIndex() == two->getIndex()) return 0;
    return 1;
}

char compareName1(Picture *one, Picture *two) {
    if(one->getName() < two->getName()) return -1;
    if(one->getName() == two->getName()) return 0;
    return 1;
}

char compareYear1(Picture *one, Picture *two) {
    if(one->getYear() < two->getYear()) return -1;
    if(one->getYear() == two->getYear()) return 0;
    return 1;
}

char compareNominations1(Picture *one, Picture *two) {
    if(one->getNominations() < two->getNominations()) return -1;
    if(one->getNominations() == two->getNominations()) return 0;
    return 1;
}

char compareRating1(Picture *one, Picture *two) {
    if(one->getRating() < two->getRating()) return -1;
    if(one->getRating() == two->getRating()) return 0;
    return 1;
}

char compareDuration1(Picture *one, Picture *two) {
    if(one->getDuration() < two->getDuration()) return -1;
    if(one->getDuration() == two->getDuration()) return 0;
    return 1;
}

char compareGenre11(Picture *one, Picture *two) {
    if(one->getGenre1() < two->getGenre1()) return -1;
    if(one->getGenre1() == two->getGenre1()) return 0;
    return 1;
}

char compareGenre21(Picture *one, Picture *two) {
    if(one->getGenre2() < two->getGenre2()) return -1;
    if(one->getGenre2() == two->getGenre2()) return 0;
    return 1;
}

char compareRelease1(Picture *one, Picture *two) {
    if(one->getRelease() < two->getRelease()) return -1;
    if(one->getRelease() == two->getRelease()) return 0;
    return 1;
}

char compareMetacritic1(Picture *one, Picture *two) {
    if(one->getMetacritic() < two->getMetacritic()) return -1;
    if(one->getMetacritic() == two->getMetacritic()) return 0;
    return 1;
}

char compareSynopsis1(Picture *one, Picture *two) {
    if(one->getSynopsis() < two->getSynopsis()) return -1;
    if(one->getSynopsis() == two->getSynopsis()) return 0;
    return 1;
}

char compareIndex(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareIndex1(two, one);
    } else {
        return compareIndex1(one, two);
    }
}

char compareName(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareName1(two, one);
    } else {
        return compareName1(one, two);
    }
}


char compareYear(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareYear1(two, one);
    } else {
        return compareYear1(one, two);
    }
}

char compareNominations(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareNominations1(two, one);
    } else {
        return compareNominations1(one, two);
    }
}

char compareRating(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareRating1(two, one);
    } else {
        return compareRating1(one, two);
    }
}

char compareDuration(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareDuration1(two, one);
    } else {
        return compareDuration1(one, two);
    }
}

char compareGenre1(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareGenre11(two, one);
    } else {
        return compareGenre11(one, two);
    }
}

char compareGenre2(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareGenre21(two, one);
    } else {
        return compareGenre21(one, two);
    }
}

char compareRelease(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareRelease1(two, one);
    } else {
        return compareRelease1(one, two);
    }
}

char compareMetacritic(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareIndex1(two, one);
    } else {
        return compareIndex1(one, two);
    }
}

char compareSynopsis(Picture *one, Picture *two, bool reverse) {
    if(reverse) {
        return compareSynopsis1(two, one);
    } else {
        return compareSynopsis1(one, two);
    }
}

#endif
