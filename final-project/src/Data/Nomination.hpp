#ifndef NOMINATIONS_HPP
#define NOMINATIONS_HPP
class Nominations {
    private:
        int index;
        int year;
        std::string award;
        bool winner;
        std::string name;
        std::string film;    
        
        Nominations();

    public:
        Nominations(int index, std::string year, std::string award, std::string winner, std::string name, std::string film);
        int getIndex();
        int getYear();
        std::string getAward();
        bool getWinner();
        std::string getName();
        std::string getFilm();
    
        void print();        
        std::string toCsvFormat();
};
#endif NOMINATIONS_HPP
