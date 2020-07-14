#ifndef PICTURE_FILTER_YEAR_HPP
#define PICTURE_FILTER_YEAR_HPP
#include "PictureFilter.hpp"
class PictureFilterYear: public PictureFilter {
    private:
        bool equalTo;
        bool greaterThan;
        bool lessThan;
        unsigned short value;
    
    public:
        PictureFilterYear();
        void setValue(std::string value);
        void setLessThan(bool lessThan);
        void setGreaterThan(bool greaterThan);
        void setEqualTo(bool equalTo);
        bool filter(Picture* picture);
};
#endif
