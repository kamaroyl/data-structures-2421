#include "../src/FileHandling/CsvWriter.hpp"
#include <string>
#include <iostream>
#include <vector>

void testCsvWriter() {
    std::string header = "A,B,C,D";
    std::vector<std::string> objectList;
    objectList.push_back("1,2,3,4");
    objectList.push_back("5,6,7,8");
    objectList.push_back("9,10,11,12");
    CsvWriter cw;
    cw.writeVectorizedObjects("test.csv", header, objectList);
}

int main() {
    testCsvWriter();
    return 0;
}
