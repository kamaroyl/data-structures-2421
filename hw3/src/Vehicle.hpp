#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <vector>

class Vehicle {
    private:
        // variables
        const int year;
        const std::string make;
        const std::string model;
        
        //Constructor
        Vehicle();

    public: 
        //constructor
        Vehicle(int year, std::string make, std::string modle);
        
        /*
         * Does a recursive binary search for a string field and returns the first item found
         * if bool model is true, search on model else search on make
         */
        friend Vehicle* binSearchRec(std::vector<Vehicle*> *vehicles, int first, int last, std::string model, bool isModel);

        /*
         * Does a recursive binary search for an int field and returns the first item found
         */
        friend Vehicle* binSearchRec(std::vector<Vehicle*> *vehicles, int frist, int last, int year); 

        /*
         * Does iterative binary search for a string field and returns the first item found
         * if bool model is true, search on model else search on make
         */
        friend Vehicle* binSearchIter(std::vector<Vehicle*> *vehicles, int first, int last, std::string model, bool isModel);

        /*
         * Does an iterative binary search for an int field and returns the first time found
         */
        friend Vehicle* binSearchIter(std::vector<Vehicle*> *vehicles, int first, int last, int year);
         
        friend std::ostream& operator<<(std::ostream& stream, const Vehicle& vehicle);
        friend void quickSortString(std::vector<Vehicle*>* vehicles, int l, int h, bool model); 
        friend void quickSortYear(std::vector<Vehicle*>* vehicles, int l, int h); 
        friend void swap(std::vector<Vehicle*>* vehicles, int a, int b);         
        friend int partitionYear(std::vector<Vehicle*>* vehicles, int l, int h); 
        friend int partitionString(std::vector<Vehicle*>* vehicles, int l, int h, bool model); 


};
#endif
