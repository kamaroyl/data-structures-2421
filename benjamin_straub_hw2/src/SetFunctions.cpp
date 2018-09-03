#include "ArrayBag.h"
#include <iostream>
#include <sstream>

//O(N^2)
ArrayBag operator+(ArrayBag& A, ArrayBag& B) {
    ArrayBag C;
    for(int i = 0; i < A.getCurrentSize(); i++) {
        C.add(A.items[i]);
    }
    for(int i = 0; i < B.getCurrentSize(); i++) {
        C.add(B.items[i]);
    }
    deduplication(&C);
    return C;
}


ArrayBag operator-(ArrayBag& A, ArrayBag& B) {
    ArrayBag C;

    for(int i = 0; i < A.getCurrentSize(); i++) {
        C.add(A.items[i]);
    }

    for(int i = 0; i < B.getCurrentSize(); i++) {
        C.remove(B.items[i]);
    }
    
    deduplication(&C);
    return C;

}


void deduplication(ArrayBag* C) {
    for(int i = C->getCurrentSize(); i > 0; i--) {
        ItemType item = C->items[i];
        int frequencyOfValue = C->getFrequencyOf(item);
        if(frequencyOfValue > 1) {
            for(int j = frequencyOfValue; j > 1; j--) { 
                C->remove(item);
            }
        }
    }
}


std::ostream& operator<<(std::ostream& stream, ArrayBag& A) {
    stream << "ArrayBag: { items: [";
    if(A.getCurrentSize() > 0) {
        for(int i = 0; i < A.getCurrentSize() - 1; i++) {
            stream << A.items[i] << ", ";
        }
    
        stream << A.items[A.getCurrentSize() -1];
    }
    stream << "] }" << std::endl;
    return stream;
}
