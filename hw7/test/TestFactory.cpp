#include "../src/EventFactory.hpp"
#include <iostream>
#include <vector>

void testFactory(){
    EventFactory ef;
    std::vector<Event> events = ef.fromFile("../resource/inputFile.csv");
    std::cout <<events.size() <<std::endl;
    for(std::vector<Event>::iterator it = events.begin(); it!= events.end(); ++it) {
        std::cout << "Event " << " id " << it->id << " type " << it->type << " time " << it->timeV << " length " << it->length << std::endl;
    }
}


int main() {
    testFactory();
    return 0;
}
