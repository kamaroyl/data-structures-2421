#ifndef PICTURE_FILTER_GENRE1_HPP
#define PICTURE_FILTER_GENRE1_HPP
#include "PictureFilter.hpp"
class PictureFilterGenre1: public PictureFilter {
    private:
        Genre value;

    public:
        PictureFilterGenre1();
        void setValue(std::string value);
        bool filter(Picture* picture);
};
#endif
