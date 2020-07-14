#ifndef PICTURE_FILTER_RATING_HPP
#define PICTURE_FILTER_RATING_HPP
#include <string>
#include "PictureFilter.hpp"
class PictureFilterRating: public PictureFilter {
    private:
        float value;
    
    public:
        PictureFilterRating();
        void setValue(std::string value);
        bool filter(Picture* picture);
};
#endif
