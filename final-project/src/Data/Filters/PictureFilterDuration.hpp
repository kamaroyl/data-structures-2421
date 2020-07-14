#ifndef PICTURE_FILTER_DURATION
#define PICTURE_FILTER_DURATION
#include <string>
#include "PictureFilter.hpp"
class PictureFilterDuration: public PictureFilter {
    private:
        unsigned short value;
    
    public:
        PictureFilterDuration();
        void setValue(std::string value);
        bool filter(Picture* picture);
};
#endif
