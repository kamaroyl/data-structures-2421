#ifndef ACTOR_MENU_HPP
#define ACTOR_MENU_HPP
#include "MenuBase.hpp"
#include <string>
class ActorMenu: public MenuBase {
    public:
        ActorMenu();
        void printMenu();
        std::string getUserInfo();
};
#endif
