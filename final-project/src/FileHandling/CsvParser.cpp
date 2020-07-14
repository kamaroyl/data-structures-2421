#include "CsvParser.hpp"

CsvParser::CsvParser() { } // default

int CsvParser::parseHeader(std::istringstream* buffer) {

    int count = 0;
    std::string garbage;

    while(true) {

        std::getline(*buffer, garbage, ',');
       
        if(garbage.length() > 0){
            count++;
        }
         if(buffer->eof()) {
            break;
        }

 
    }
    return count;
}

std::vector<std::string>* CsvParser::parseLine(std::istringstream* buffer, int count) {
    std::string tmpValue;
    std::vector<std::string>* values = new std::vector<std::string>();
    int length = 0;
    while(true) {
        std::getline(*buffer, tmpValue, ',');
        if(length < count) {  
            values->push_back(tmpValue);
            length++;
        } else {
           (*values)[length-1] += ",";
           (*values)[length-1] += tmpValue; 
        }
        
        if(buffer->eof()) {
            break;
        }
    }

    return values;
}

std::vector<std::vector<std::string>*>* CsvParser::parseCsv(std::string filepath) {
    std::ifstream fs(filepath);
    int lineNumber = 0;
    std::vector<std::string> lines;
    std::string tmpLine;
    std::istringstream buffer;
    int symbolsPerLine;
    std::vector<std::vector<std::string>*>* result = new std::vector<std::vector<std::string>*>();

    if(fs.is_open()) {
        //Pull in strings from file
        while(true) {

            if(!std::getline(fs, tmpLine)) {

                if(fs.eof()) {
                    break;
                }

                std::cout << "failed to read in line at: " << lineNumber << std::endl;
                lineNumber++;
                continue;

            }

            lines.push_back(tmpLine);
            lineNumber++;

        }

        fs.close();
    } //File parsing finished

    if(lines.size() > 0) {

        //Iterate Through Vector
        std::vector<std::string>::iterator it = lines.begin();
        buffer.str(*it);
        int symbolsPerLine = this->parseHeader(&buffer);
        it++; // start iterator at second position

        for(it; it != lines.end(); ++it) {
            buffer.clear(); 
            buffer.str(*it);
            result->push_back(this->parseLine(&buffer, symbolsPerLine)); // insert pointer to string vector into results vector
        }
    }
    return result;
}
