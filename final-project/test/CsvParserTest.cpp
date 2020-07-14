#include "../src/FileHandling/CsvParser.hpp"


std::string csvFormat1 = "A,B,C,D,E";
std::string csvFormat2 = "A,B,C,D,E,";

void testParseHeaderFmt1() {
    CsvParser csvParser;
    std::istringstream *ss = new std::istringstream(csvFormat1);
    int result = csvParser.parseHeader(ss);
    std::cout << "Length: " << result << std::endl;
    delete ss;
}

void testParseHeaderFmt2() {
    CsvParser csvParser;
    std::istringstream *ss = new std::istringstream(csvFormat2);
    int result = csvParser.parseHeader(ss);
    std::cout << "Length: " << result << std::endl;
    delete ss;
}

void testParseLineFmt1() {
    CsvParser csvParser;
    std::istringstream *ss = new std::istringstream(csvFormat1);
    std::vector<std::string>* line = csvParser.parseLine(ss, 5); 
    for(int i = 0; i < line->size(); i++) {
        std::cout << (*line)[i] << std::endl;
    }
    delete ss;
    delete line;
}

void testParseLineFmt2() {
    CsvParser csvParser;
    std::istringstream *ss = new std::istringstream(csvFormat2);
    std::vector<std::string>* line = csvParser.parseLine(ss, 5);
    for(int i = 0; i < line->size(); i++) {
        std::cout << (*line)[i] << std::endl;
    }
    delete ss;
    delete line;
}

void testFileParseFmt1() {
    CsvParser csvParser;
    std::vector<std::vector<std::string>*>* result = csvParser.parseCsv("../resource/actor-actress.csv");
    for(int i = 0; i < result->size(); i++) {
        for(int j = 0; j < (*result)[i]->size(); j++) {
            std::cout << (*(*result)[i])[j] << std::endl;
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < result->size(); i++) {
        delete (*result)[i];
    }
    delete result;
}

int main() {
    testParseHeaderFmt1();
    testParseHeaderFmt2();
    testParseLineFmt1();
    testParseLineFmt2();
    testFileParseFmt1();
    return 0;
}
