#ifndef PICTURE_FILTER_GENRE1_HPP
#define PICTURE_FILTER_GENRE1_HPP
#include "PictureFilter.hpp"
class PictureFilterMonth: public PictureFilter {
    private:
        Month value;

    public:
        PictureFilterMonth();
        void setValue(std::string value);
        bool filter(Picture* picture);
};
#endif
