#include "Event.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Event::Event(Type type, int timeV, int length): type(type), timeV(timeV), length(length){
    
    this->id = this->generateUUID();
}

Event::Event(std::string id, Type type, int timeV, int length): id(id), type(type), timeV(timeV), length(length){
}


bool CompareEvent::operator()(Event const &event1, Event const &event2) {
    return event1.timeV > event2.timeV;
}

//faking a uuid v4
std::string Event::generateUUID(){
    int r = time(NULL);   
    srand(r);
    std::string out;
    std::stringstream ss;
    for(int i=0; i < 3; i++) {
        int random = rand();
        ss << std::hex << random;
        std::string tmp (ss.str());
        out += tmp;
        ss.clear();
    }
    std::string uuid;
    for(int i = 0; i < 36; i++){
        if(i==9) uuid+='-';
        else if(i==14) uuid+='-';
        else if(i==19) uuid+='-';
        else if(i==24) uuid+='-';
        else uuid += out[i];
    }
    return uuid;
}
