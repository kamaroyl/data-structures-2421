#ifndef FILE_HANDLING_HPP
#define FILE_HANDLING_HPP
#include <fstream>
#include <iostream>
#include <sstream>

#include "./Vehicle.hpp"

class FileHandler {
    public:
        FileHandler();
        std::vector<Vehicle*>* readFromFile(std::string filePath); 
};
#endif
