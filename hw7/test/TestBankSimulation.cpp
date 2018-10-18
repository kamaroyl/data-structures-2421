#include "../src/BankSimulation.hpp"
#include <vector>

void testConstructor() {
    std::vector<Event> events;
    Event event1("A",ARRIVAL, 1, 5);
    events.push_back(event1);
    Event event2("B", ARRIVAL, 2, 5);
    events.push_back(event2);
    Event event3("C", ARRIVAL, 4, 5);
    events.push_back(event3);
    Event event4("D", ARRIVAL, 20, 5);
    events.push_back(event4);
    Event event5("E", ARRIVAL, 22, 5);
    events.push_back(event5);
    Event event6("F", ARRIVAL, 24, 5);
    events.push_back(event6);
    Event event7("G", ARRIVAL, 26, 5);
    events.push_back(event7);
    Event event8("H", ARRIVAL, 28, 5);
    events.push_back(event8);
    Event event9("I", ARRIVAL, 30, 5);
    events.push_back(event9);
    Event event10("J", ARRIVAL,88, 3);
    events.push_back(event10);
    BankSimulation be;
    be.loadEvents(events);
    be.simulate();
}

void testLoadEvents() {

}


int main() {
   testConstructor(); 
    return 0;
}
