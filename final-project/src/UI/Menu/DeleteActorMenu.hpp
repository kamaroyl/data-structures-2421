#ifndef DELETE_ACTOR_MENU_HPP
#define DELETE_ACTOR_MENU_HPP
#include <string>
#include "../../Data/Actor.hpp"
#include "MenuBase.hpp"
class DeleteActorMenu: public MenuBase {
    private:
        Actor* actor;
        std::string confirmMenu();    
    public:
        DeleteActorMenu();
        void printMenu();
        std::string getUserInfo();
        void setActor(Actor* actor);
        Actor* getActor();
        void clear();
};
#endif
