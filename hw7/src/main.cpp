#include "Event.hpp"
#include "EventFactory.hpp"
#include "BankSimulation.hpp"

std::string askForFilePath(std::string defaultPath) {
    std::string input;
    std::cout << std::endl << "please give a file path. Will default to "  << defaultPath << std::endl;
    std::getline(std::cin, input);
    if(!input.empty()) {
        defaultPath = input;
    }
    return defaultPath;
}
int main() {
    //default file path
    std::string defaultFilePath = "resource/inputFile.csv";


    //Parse csv
    std::string fp = askForFilePath(defaultFilePath);
    EventFactory ef;
    std::vector<Event> events = ef.fromFile(fp);
    
    BankSimulation bs;

    bs.loadEvents(events);
    bs.simulate();
 
    return 0;
      
}
