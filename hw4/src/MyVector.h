#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
/******************************************
 * Ben Straub - 830276423                 *
 ******************************************/
//forward declare

namespace HW4{ class MyVector; }
std::ostream& operator<<(std::ostream& stream, HW4::MyVector myVector);


/*Defines a MyVector type which mirrors the STL vector class.  It uses templates and dynamic memory allocation*/

namespace HW4
{
typedef int T;
class MyVector
{
private:
    int vsize;
    T* vec;

public:
    MyVector();
    T operator[] (int index) const;
    void pop_back();
    void push_back(T value);
    int size() const; //returns the vector size
    bool empty() const;//determine if is empty
    int search(T Value);
    
    //print the vector - size and values
    friend std::ostream& ::operator<<(std::ostream& stream, MyVector myVector);
};
}//namespace
#endif
