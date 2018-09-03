#include "FileFunction.hpp"
#include <sstream>
/*
 * Takes a string stream, creates an Array bag and populates
 * it with ints from string stream
 */
ArrayBag* arrayBagFactory(std::string* intsString) {
    std::stringstream ss;
    int tempInt;
    std::stringstream::pos_type pos;
    std::string errorString;

    ArrayBag* arrayBag = new ArrayBag();

    ss << *intsString;
    while(!ss.eof()) {
        pos = ss.tellg();
        ss >> tempInt;
        
        if(ss.fail()) {
            std::cout << "Input contains non-integer data" << std::endl;
            std::cout << "Failed at " << pos << std::endl;
            ss.clear();
            ss >> errorString;
            std::cout << "Error: " << errorString << std::endl;
            continue;
        }
        arrayBag->add(tempInt);
    }
    return arrayBag;
}
