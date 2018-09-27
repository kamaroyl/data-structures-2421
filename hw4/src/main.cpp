#include "MyVector.h"
#include <iostream>
#include <string>
/******************************************
 * Example main - shows usage of MyVector *
 * Ben Straub 830276423                   *
 *                                        *
 ******************************************/
using namespace HW4;

std::string b2s(bool val) {
    if(val) return "true";
    return "false";
}

int main() {
    MyVector vector;
    std::cout << vector << std::endl;
    std::cout << "isEmpty: " << b2s(vector.empty()) << std::endl;
    std::cout << "size: " << vector.size() << std::endl;
    std::cout << std::endl;
    vector.push_back(1);
    std::cout << vector << std::endl;
    std::cout << "isEmpty: " << b2s(vector.empty()) << std::endl;
    std::cout << "size: " << vector.size() << std::endl << std::endl;
    vector.push_back(2);
    std::cout << vector << std::endl;
    std::cout << "isEmpty: " << b2s(vector.empty()) << std::endl;
    std::cout << "size: " << vector.size() << std::endl << std::endl;
    std::cout << "Index of value 2 is " << vector.search(2) << std::endl << std::endl;
    vector.pop_back();
    std::cout << vector << std::endl;
    std::cout << "isEmpty: " << b2s(vector.empty()) << std::endl;
    std::cout << "size: " << vector.size() << std::endl << std::endl;
    vector.pop_back();
    std::cout << vector << std::endl;
    std::cout << "isEmpty: " << b2s(vector.empty()) << std::endl;
    std::cout << "size: " << vector.size() << std::endl;
    std::cout << "Done" << std::endl << std::endl;
    return 0;
}
