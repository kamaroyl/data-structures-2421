#ifndef SEARCH_ACTOR_MENU_HPP
#define SEARCH_ACTOR_MENU_HPP
#include "MenuBase.hpp"
#include <string>
class SearchActorMenu: public MenuBase {
    private:
        std::string year;
        std::string award;
        std::string winner;
        std::string name;
        std::string film;

    public:
        SearchActorMenu();
        void printMenu();
        std::string getUserInfo();
        
        void setYearFilter();
        void setAwardFilter();
        void setNameFilter();
        void setWinnerFilter();
        void setFilmFilter();
        
        std::string getYear();
        std::string getAward();
        std::string getWinner();
        std::string getName();
        std::string getFilm();
};
#endif
