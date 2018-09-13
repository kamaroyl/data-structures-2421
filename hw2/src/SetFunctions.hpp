#ifndef SET_FUNCTIONS_H
#define SET_FUNCTIONS_H
#include "./ArrayBag.h"
#include <iostream>

class SetFunctions {
    private:
    
    public:
        ArrayBag operator +(ArrayBag& A, ArrayBag& B);
        ArrayBag operator -(ArrayBag& A, ArrayBag& B);
        void deduplication(ArrayBag* C);
        std::ostream& operator<<(std::ostream& stream, ArrayBag& A);
};

#endif
