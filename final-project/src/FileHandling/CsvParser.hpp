#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class CsvParser {

    public:
        CsvParser();
        std::vector<std::vector<std::string>*>* parseCsv(std::string filePath);
        int parseHeader(std::istringstream* buffer);
        std::vector<std::string>* parseLine(std::istringstream* buffer, int count); 

};
#endif
