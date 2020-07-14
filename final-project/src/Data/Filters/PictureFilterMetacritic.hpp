#ifndef PICTURE_FILTER_METACRITIC_HPP
#define PICTURE_FILTER_METACRITIC_HPP
#include <string>
#include "PictureFilter.hpp"
class PictureFilterMetacritic: public PictureFilter {
    private:
        unsigned short value;
    
    public:
        PictureFilterMetacritic();
        void setValue(std::string value);
        bool filter(Picture* picture);
};
#endif
