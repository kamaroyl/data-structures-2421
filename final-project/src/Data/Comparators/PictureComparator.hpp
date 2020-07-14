#ifndef PICTURE_COMPARATOR_HPP
#define PICTURE_COMPARATOR_HPP
#include "../Picture.hpp"

/*
 * index       - 1
 * name        - 2
 * year        - 3
 * nominations - 4
 * rating      - 5
 * duration    - 6
 * genre1      - 7
 * genre2      - 8
 * release     - 9
 * metacritic  - 10
 * synopsis    - 11
 */

class PictureField {
    public:
        unsigned char number; //which field we are dealing with
        char value;
        char (*func)(Picture *, Picture *, bool);
        
        PictureField() {
            this->number = 0;
            this->value = 0;
        }
};

class PictureComparator {
    private:
        const unsigned short size = 11;
        PictureField * fields;
        
        void setField(unsigned short number, char value);
    public:
        PictureComparator();
        PictureComparator(PictureComparator* pc);
        ~PictureComparator();
        char* copyFieldValues();
        char operator()(Picture *one, Picture *two);
        void setIndex(char value);
        void setName(char value);
        void setYear(char value);
        void setNominations(char value);
        void setRating(char value);
        void setDuration(char value);
        void setGenre1(char value);
        void setGenre2(char value);
        void setRelease(char value);
        void setMetacritic(char value);
        void setSynopsis(char value);

        void insertionSortFields(PictureField* fields, unsigned short size);
        void clear();
};
#endif 
