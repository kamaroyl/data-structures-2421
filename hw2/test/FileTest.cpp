
#include "../src/ArrayBag.h"
#include "../src/FileFunction.hpp"
#include <fstream>
#include <iostream>
#include <string>

void testArrayBagFactory(std::string* readString) {
    ArrayBag* test1 = arrayBagFactory(readString);
    std::cout << *test1 << std::endl;
}

void testArrayBagFactoryAddition(std::string* readString1, std::string* readString2) {
    ArrayBag* test1 = arrayBagFactory(readString1);
    std::cout << "test1: " << *test1;
    ArrayBag* test2 = arrayBagFactory(readString2);
    std::cout << "test2: " << *test2;
    ArrayBag test3 = *test1 + *test2;
    std::cout << "Union:    " << test3; 
    std::cout << "expected: ArrayBag: { items: [6, 19, -100, 8, -4, 16, 15, 7, 11, 12, 4, 3, 9, 5, 1] }"; 
    
}

int main() {
    //before
    std::ifstream infile("../resource/setInput.txt");
    std::string * readString1 = new std::string();
    std::string * readString2 = new std::string();
    getline(infile, *readString1);
    getline(infile, *readString2);
   
    //tests
    testArrayBagFactory(readString1);
    testArrayBagFactoryAddition(readString1,readString2);
    return 0;
}
