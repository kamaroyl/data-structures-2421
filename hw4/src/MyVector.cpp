#include "MyVector.h"
#include <iostream>
#include <limits>
/************************************************************************
 *  Bad vector implementation                                           *
 *  Ben Straub - 830276423                                              *
 *  A toy vector that has an O(n) insertion and deletion due to a full  *
 *  copy of the array in either case                                    *
 ************************************************************************/
HW4::MyVector::MyVector(): vec(nullptr), vsize(0) {
}

/*************************************************************
 *     if the index falls within the size of the vector      *
 *     return the value at that index, otherwise, allow      *
 *     underlying code to throw exception since we can't     *
 *************************************************************/
HW4::T HW4::MyVector::operator[] (int index) const{
    if(index < this->vsize) return this->vec[index];
    std::cout << "Index " << index;
    std::cout << " falls outside of vector of size: ";
    std::cout << this->vsize << std::endl;
    return this->vec[index];
}

/**************************************************************
 *    Remove the last element of the array, Shrink array      *
 *    return nothing                                          *
 **************************************************************/
void HW4::MyVector::pop_back() {
    if(this->vsize > 0) {
        this->vsize--;
        //Abuse the fact that last item is at index vsize - 1
        // and use the next vsize of the new array
        HW4::T* tempVec = new HW4::T[vsize];

        //copy old array into new array
        for(int i = 0; i < vsize; i++){
            tempVec[i] = this->vec[i];
        }   

        this->vec = tempVec;
        return;
    }
}

/************************************************************
 *    Grow Array, add element at the end, return nothing    *
 ************************************************************/
void HW4::MyVector::push_back(HW4::T value) {
    //If the size is less than the maximum integer value
    if(this->vsize < std::numeric_limits<int>::max()) {
        //One addition vs two subtractions
        HW4::T* tempVec = new HW4::T[vsize + 1];
        
        //copy old array into new array
        for(int i = 0; i < vsize; i++) {
            tempVec[i] = this->vec[i];
        }
        
        this->vec = tempVec;
        this->vec[vsize] = value; 
        this->vsize++;
        return;
    }    
}

// returns vsize
int HW4::MyVector::size() const{
    return this->vsize;
}

bool HW4::MyVector::empty() const{
    return (this->vsize == 0);
}

//Linear search over array
int HW4::MyVector::search(HW4::T Value) {
    for(int i = 0; i < this->vsize; i++) {
        if(this->vec[i] == Value) return i;
    }
    //if you can't find the value, return -1
    return -1;
}

std::ostream& operator<<(std::ostream& stream, const HW4::MyVector myVector) {
    stream << "MyVector: { " ;
    stream << "vsize: " << myVector.size() << ", ";
    stream << "[";
    if(myVector.size() > 0 ) {
        for(int i=0; i < (myVector.size() - 1); i++) {
            stream << myVector[i] << ", ";
        }
        stream << myVector[myVector.size() - 1];
    }
    stream << "]}" << std::endl;
    return stream;
}
