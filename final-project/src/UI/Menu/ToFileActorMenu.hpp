#ifndef TO_FILE_ACTOR_MENU_HPP
#define TO_FILE_ACTOR_MENU_HPP
#include "MenuBase.hpp"
#include <string>
class ToFileActorMenu: public MenuBase {
    private:
        std::string filePath;    
    public:
        ToFileActorMenu();
        void printMenu();
        std::string getUserInfo();
        void clear();
        std::string getFilePath();
};
#endif
