#ifndef PICTURE_FILTER_NOMINATIONS_HPP
#define PICTURE_FILTER_NOMINATIONS_HPP
#include <string>
#include "PictureFilter.hpp"
class PictureFilterNominations: public PictureFilter {
    private:
        unsigned short value;
    
    public:
        PictureFilterNominations();
        void setValue(std::string value);
        bool filter(Picture* picture);
};
#endif
