#include "CsvWriter.hpp"
void CsvWriter::writeHeader(std::string header, std::ofstream& fp) {
    fp << header << std::endl;
}

void CsvWriter::writeString(std::string object, std::ofstream& fp) {
    fp << object << std::endl;
}

void CsvWriter::writeVectorizedObjects(std::string filename, std::string header, std::vector<std::string> objectList) {
    std::ofstream csvFile;
    csvFile.open(filename);
    writeHeader(header, csvFile);
    for(std::vector<std::string>::iterator it = objectList.begin(); it != objectList.end(); ++it) {
        writeString(*it, csvFile); 
    }
    csvFile.close();
}
