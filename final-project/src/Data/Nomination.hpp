#ifndef NOMINATIONS_HPP
#define NOMINATIONS_HPP
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
class Nominations {
    private:
        unsigned int index;
        unsigned short year;
        std::string award;
        bool winner;
        std::string name;
        std::string film;    
        
        Nominations();

    public:
        Nominations(unsigned int index, std::string year, std::string award, std::string winner, std::string name, std::string film);
        unsigned int getIndex();
        unsigned short getYear();
        std::string getAward();
        bool getWinner();
        std::string getName();
        std::string getFilm();
    
        void print();        
        std::string toCsvFormat();
};
#endif
