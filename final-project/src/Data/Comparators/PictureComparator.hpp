#ifndef PICTURE_COMPARATOR_HPP
#define PICTURE_COMPARATPR_HPP
#include "../Picture.hpp"
class PictureComparator {
    bool operator()(Picture const &one, Picture const *two);
};
#endif 
