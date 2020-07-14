#ifndef EDIT_ACTOR_MENU_HPP
#define EDIT_ACTOR_MENU_HPP
#include <string>
#include "../../Data/Actor.hpp"
#include "MenuBase.hpp"
class EditActorMenu: public MenuBase {
    private:
        Actor* actor;
        unsigned int index;
        std::string year;
        std::string award;
        std::string winner;
        std::string name;
        std::string film;
    
    public:
        EditActorMenu();
        void setIndex(unsigned int index);
        void setActor(Actor* actor);
        
        void printMenu();
        unsigned int getIndex();
        std::string getUserInfo();
        bool submit();
        void setYear();
        void setAward();
        void setWinner();
        void setName();
        void setFilm();
        void clear();
};
#endif
