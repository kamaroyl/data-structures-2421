#include "EventFactory.hpp"

std::vector<Event> EventFactory::fromFile(std::string filepath) {
    std::ifstream fs(filepath);
    std::vector<Event> events;
    int lineNumber = 0;
    std::string tmp; 
    std::stringstream ss;
    
    if(fs.is_open()) {
        std::getline(fs, tmp);
        std::cout << tmp << std::endl; 
        while(true) {
            if(!std::getline(fs, tmp)) {
                if(fs.eof()) {
                    break;
                }
                std::cout << "failed to read in line " << lineNumber << std::endl;
            }
            lineNumber++;

            std::string timeValString;
            int    timeVal;
            std::string lengthValString;
            int    lengthVal;
            ss << tmp;
            std::getline(ss,timeValString, ',');
            std::istringstream(timeValString) >> timeVal;
            std::getline(ss, lengthValString, ',');
            std::istringstream(lengthValString) >> lengthVal;  
            Event tmpEvent(std::to_string(lineNumber),ARRIVAL, timeVal, lengthVal);
            ss.clear();
            events.push_back(tmpEvent);
        }
    }
    fs.close();
    return events;
}
