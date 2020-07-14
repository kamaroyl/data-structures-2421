#ifndef PICTURE_FILTER_SYNOPSIS_HPP
#define PICTURE_FILTER_SYNOPSIS_HPP
#include <string>
#include "../Picture.hpp"
#include "PictureFilter.hpp"
class PictureFilterSynopsis: public PictureFilter {
    private:
        std::string value;

    public:
        PictureFilterSynopsis();
        void setValue(std::string value);
        bool filter(Picture* picture); //Partial Comparison
};
#endif
