#ifndef PICTURE_FILTER_NAME_HPP
#define PICTURE_FILTER_NAME_HPP
#include <string>
#include "../Picture.hpp"
#include "PictureFilter.hpp"
class PictureFilterName: public PictureFilter {
    private:
        std::string value;

    public:
        PictureFilterName();
        void setValue(std::string value);
        bool filter(Picture* picture); //Partial Comparison
};
#endif
