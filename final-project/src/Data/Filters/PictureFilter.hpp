#ifndef PICTURE_FILTER_HPP
#define PICTURE_FILTER_HPP
#include "../Picture.hpp"
#include <string>
#include <iostream>
class PictureFilter {
    public:
        virtual void setValue(std::string value);
        virtual bool filter(Picture* picture);
};
#endif
