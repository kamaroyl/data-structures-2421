#include <iostream>
#include <string>
#include "../src/Event.hpp"

std::string bool2string(bool val){
    if(val) return "true";
    return "false";
}

void testEventConstruction() {
    Event event(ARRIVAL, 1234, 3);
    std::cout << "id: " << event.id << " type: " << event.type << " time: " << event.time << " duration: " << event.length << std::endl;
    Event copy(event.id, DEPARTURE, 1234,3);
    std::cout << "id: " << copy.id << " type: " << copy.type << " time: " << copy.time << " duration: " << copy.length << std::endl;

}

void testCompare() {
    Event event1(ARRIVAL, 1, 2);
    Event event2(ARRIVAL, 2, 3);
    CompareEvent ce;
    bool val = ce(event1, event2);
    std::cout << "1 > 2" << bool2string(val) << std::endl;
}

void testUuidGeneration() {
    Event event1(ARRIVAL, 1, 2);
    
}

int main() {
    testEventConstruction();
    testCompare();
    return 0;
}
