#ifndef CSV_WRITER_HPP
#define CSV_WRITER_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CsvWriter {
    public:
        void writeHeader(std::string header, std::ofstream& fp);
        void writeVectorizedObjects(std::string fileHandle, std::string header, std::vector<std::string> objectList);
        void writeString(std::string object, std::ofstream& fp);
};
#endif
