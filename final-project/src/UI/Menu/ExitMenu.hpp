#ifndef EXIT_MENU_HPP
#define EXIT_MENU_HPP
#include "MenuBase.hpp"
#include <string>
class ExitMenu: public MenuBase {
    public:
      ExitMenu();
      void  printMenu();
      std::string getUserInfo();
};
#endif
