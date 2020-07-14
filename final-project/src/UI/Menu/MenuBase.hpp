#ifndef BASE_MENU_HPP
#define BASE_MENU_HPP

#include <cctype>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>


class MenuBase {
         
    public:
        MenuBase();
        virtual void printMenu();
        virtual std::string getUserInfo();
        
        //Helper functions
        void printLine(int col);
        void printHeaderPiece(std::string title, int col);
        void printHeader(std::string statement);
        void clearScreen();
        bool isNumber(std::string* s);
        bool isFloat(std::string* s);
};
#endif
