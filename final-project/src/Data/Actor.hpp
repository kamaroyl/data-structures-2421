#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

class Actor {
    private:
        unsigned int index;
        unsigned short year;
        std::string award;
        bool winner; 
        std::string name;
        std::string film;

    
    public:
        Actor();
        Actor(unsigned int index, std::string year, std::string award, std::string winner, std::string name, std::string film);
        unsigned int getIndex();
        unsigned short getYear();
        std::string getAward();
        bool getWinner();
        std::string getName();
        std::string getFilm();
        
        void setIndex(unsigned int index);
        void setYear(std::string year); 
        void setAward(std::string award); 
        void setWinner(std::string winner);
        void setName(std::string name);
        void setFilm(std::string film);

        void print();
        std::string toCsvFormat();
        
        friend std::ostream& operator<<(std::ostream& os, Actor& actor);
};
#endif
