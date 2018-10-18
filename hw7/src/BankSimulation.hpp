#ifndef BANK_SIMULATION_HPP
#define BANK_SIMULATION_HPP
#define NA -1
#include <iostream>
#include <vector>
#include <queue>
#include "./Event.hpp"
/*
 *  Implementation based off pg 407 Data abstraction and problem solving with c++
 */
class BankSimulation {
    private: 
       std::queue<Event> bankLine;
       std::priority_queue<Event, std::vector<Event>, CompareEvent> events;
       bool isTellerFree;
       int currentTime;
       float runningSum;
       int numberOfCustomers;
       
    public:
        BankSimulation();
        void loadEvents(std::vector<Event> events);
        void clearEvents();
        void processArrival(Event arrivalEvent);
        void processDeparture(Event departureEvent);
        void simulate();
        void addRunningSum(int wait);
 
};
#endif
