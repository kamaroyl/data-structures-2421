#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP
#include "MenuBase.hpp"
#include <string>
class MainMenu: public MenuBase {
    public:
      MainMenu();
      void  printMenu();
      std::string getUserInfo();
};
#endif
