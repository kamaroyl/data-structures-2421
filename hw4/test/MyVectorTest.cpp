#include "../src/MyVector.h"
#include <iostream> 

using namespace HW4;


void testConstructor() {
    std::cout << "testConstructor()" << std::endl;
    MyVector myVector;
    std::cout << myVector << std::endl;    

}

void testPush() {
    std::cout << "testPush()" << std::endl;
    MyVector myVector;
    myVector.push_back(27);
    std::cout << myVector << std::endl;
    
}

void testPop() {
    std::cout << "testPop()" << std::endl;
    MyVector myVector;
    myVector.push_back(27);
    myVector.pop_back();
    std::cout << myVector << std::endl;
}

void testSize() {
    std::cout << "testSize()" << std::endl;
    MyVector myVector;
    std::cout << "myVector size at init: " << myVector.size() << std::endl;
    std::cout << "size should be: 0" << std::endl;

    myVector.push_back(9999);
    std::cout << "myVector size after pushback: " << myVector.size() << std::endl;
    std::cout << "size should be: 1" << std::endl;
    
    myVector.pop_back();
    std::cout << "myVector size after popback: " << myVector.size() << std::endl;
    std::cout << "size should be: 0" << std::endl;
    std::cout << std::endl;
}

void testEmpty() {
    std::cout << "testEmpty()" << std::endl;
    MyVector myVector;
    std::cout << "MyVector at init: " << myVector.empty() << std::endl;
    std::cout << "MyVector should be empty" << std::endl;
    myVector.push_back(462);
    std::cout << "MyVector after pushBack: " << myVector.empty() << std::endl;
    std::cout << "MyVector should not be empty" << std::endl;
    myVector.pop_back();
    std::cout << "MyVector after popBack: " << myVector.empty() << std::endl;
    std::cout << "MyVector should be empty" << std::endl;
    std::cout << std::endl;
}

void testSearch() {
    std::cout << "testSearch()" << std::endl;
    MyVector myVector;
    myVector.push_back(3);
    myVector.push_back(5);
    std::cout << myVector << std::endl;
    std::cout << "index of value 5: " << myVector.search(5) << std::endl;
    std::cout << "should be 1" << std::endl;
    std::cout << std::endl;
}

int main() {
    testConstructor(); 
    testPush();
    testPop();
    testSize();
    testEmpty(); 
    testSearch();
    return 0;
}
