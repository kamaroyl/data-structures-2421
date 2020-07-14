#ifndef ADD_ACTOR_MENU_HPP
#define ADD_ACTOR_MENU_HPP
#include <string>
#include "../../Data/Actor.hpp"
#include "MenuBase.hpp"
class AddActorMenu: public MenuBase {
    private:
        unsigned int index;
        std::string year;
        std::string award;
        std::string winner;
        std::string name;
        std::string film;

    public:
        AddActorMenu();
        void printMenu();
        std::string getUserInfo();
        Actor* getActor();
        
        bool submit();
        void clear();
        
        void setIndex(unsigned int index);
        void setYear();
        void setAward();
        void setWinner();
        void setName();
        void setFilm();
};
#endif
