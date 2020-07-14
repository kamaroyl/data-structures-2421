#ifndef PICTURE_FILTER_GENRE2_HPP
#define PICTURE_FILTER_GENRE2_HPP
#include "PictureFilter.hpp"
class PictureFilterGenre2: public PictureFilter {
    private:
        Genre value;

    public:
        PictureFilterGenre2();
        void setValue(std::string value);
        bool filter(Picture* picture);
};
#endif
