#include "ArrayBag.h"
#include "FileFunction.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;
    std::string path = "./resource/setInput.txt";

    std::cout << "Give a filepath to a file with two space delimited lines of ints." << std::endl;
    std::cout << "If none is given, it will default to ./resouce/setInput.txt";
    std::cout << std::endl;

    std::getline(std::cin, input);
    if(!input.empty()) {
        std::stringstream stream(input);
        stream >> path;    
    }

    std::cout << "Path will be: " << path << std::endl;
    std::ifstream inFile(path);
    std::string* readString1 = new std::string();
    std::string* readString2 = new std::string();
    getline(inFile, *readString1);
    getline(inFile, *readString2);
    
    std::cout <<"Creating Bags from input" << std::endl;
    ArrayBag* arrayBag1 = arrayBagFactory(readString1);
    std::cout << "First bag: " << *arrayBag1;
    ArrayBag* arrayBag2 = arrayBagFactory(readString2);  
    std::cout << "Second bag: " << *arrayBag2;  
    ArrayBag unionBag = *arrayBag1 + *arrayBag2;
    std::cout << "bag1 + bag2 = " << unionBag;
    ArrayBag diffBag = *arrayBag1 - *arrayBag2;
    std::cout << "bag1 - bag2 = " << diffBag;
    return 0;
}
