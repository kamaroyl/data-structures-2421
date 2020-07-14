#ifndef PICTURE_MENU_HPP
#define PICTURE_MENU_HPP
#include <string>
#include "MenuBase.hpp"
class PictureMenu: public MenuBase {
    public:
        PictureMenu();
        void printMenu();
        std::string getUserInfo();
};
#endif
