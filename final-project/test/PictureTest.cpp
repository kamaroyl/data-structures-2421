#include "../src/Data/Picture.hpp"
#include <iostream>
#include <string>

void printHeader(std::string header) {
    std::cout << "======== " << header << " ========" << std::endl;
}

void testConstruction() {
    printHeader("testConstruction");
    Picture picture(1, "test", "1989", "1", "6.34", "118", "Comedy", "Drama", "December", "68", "This is a synopsis");
    picture.print();
    std::cout << picture;
}

void testFormatCsv() {
    printHeader("testFormatCsv");
    Picture picture(2, "test", "2010", "0", "6.34", "665", "Drama", "Comedy", "November", "98", "A summary");
    std::cout << picture.toCsvFormat() << std::endl;
}

int main() {
    testConstruction();
    testFormatCsv();
    return 0;
}
