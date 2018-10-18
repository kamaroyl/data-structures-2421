#include "BankSimulation.hpp"
/*
    Time   Wait Length Depart Dform
     1       0     5    6       6
     2       4     5    

    n(Departure) = n(Wait) + n(Trans)
    n(Wait) = n-1(Departure) - n(Arrival)
    n(Wait) = n-1(Wait) + n(Trans) - n(Arrival)
 */

BankSimulation::BankSimulation(): isTellerFree(true), currentTime(0), runningSum(0), numberOfCustomers(0){ }

void BankSimulation::loadEvents(std::vector<Event> events) {
    for(std::vector<Event>::iterator it = events.begin(); it != events.end(); ++it) {
        this->events.push(*it);
    }
}

void BankSimulation::processArrival(Event arrivalEvent) {
    std::cout << "customer " << arrivalEvent.id << " arrived at " << arrivalEvent.timeV << std::endl;
    this->events.pop();
    this->numberOfCustomers++;
    if(this->bankLine.empty() && this->isTellerFree) {
       int departureTime = this->currentTime + arrivalEvent.length;
       Event departureEvent(arrivalEvent.id, DEPARTURE, departureTime, NA);
       this->events.push(departureEvent);
       this->isTellerFree = false;
    } else {
        this->bankLine.push(arrivalEvent);
    } 
}

void BankSimulation::processDeparture(Event departureEvent) {
    std::cout << "customer " << departureEvent.id << " departed at " << departureEvent.timeV << std::endl;
    this->events.pop();
    if(!bankLine.empty()) {
        Event customer = bankLine.front();
        bankLine.pop();
        this->addRunningSum(departureEvent.timeV - customer.timeV);
        int departureTime = this->currentTime + customer.length;
        Event departureEvent(customer.id, DEPARTURE, departureTime, NA);
        this->events.push(departureEvent);
    } else {
        this->isTellerFree = true;
    }
}

void BankSimulation::simulate() {
    std::cout << "---- Start of Simulation ----" << std::endl;
    while(!this->events.empty()){
        Event event = this->events.top();
        this->currentTime = event.timeV;
        if( event.type == ARRIVAL ) {
            this->processArrival(event);
        } else {
            this->processDeparture(event);
        }
    }
    std::cout << "---- End of Simulation ----" << std::endl;
    std::cout << "Total Number of customers: " << this->numberOfCustomers << std::endl;
    std::cout << "Total Wait time: " << this->runningSum << std::endl;
    std::cout << "Average wait time: " << (this->runningSum/this->numberOfCustomers) << std::endl;
}

void BankSimulation::addRunningSum(int waitTime) {
    if(waitTime > 0) {
        this->runningSum += waitTime;
    }
}
