#ifndef EVENT_HPP
#define EVENT_HPP
#include <sstream>
#include <string>
enum Type {
    ARRIVAL,
    DEPARTURE
};

class Event {
    public:
        //Constructor 
        Event(Type type, int time, int length);
        Event(std::string id, Type type, int time, int length);
        //variables
        Type type;
        std::string id;
        int timeV;
        int length;
           
    private:
        std::string generateUUID();
        Event();
};

class CompareEvent {
    public:
        bool operator()(Event const & event1, Event const & event2);
};
#endif
