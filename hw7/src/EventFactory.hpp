#ifndef EVENT_FACTORY_HPP
#define EVENT_FACTORY_HPP
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include "Event.hpp"
class EventFactory {
    public:
        std::vector<Event> fromFile(std::string filePath);

};

#endif
