#ifndef MENU_HPP
#define MENU_HPP

#include <map>
#include <string>

class MenuData {
    private:
        std::string description;
        void (*menuFunction)();
}
0
//A simple class that represents the menus
class Menu {

    private:
        //map of fields to functions
        std::map<std::string, void*> fields;

    public:
        void printFields(); //print all keys in map
        bool conainsKey(std::string key); //check if menu has the option
        void executeFieldFunction(std::string field); //execute function pointer mapped to string

};

#endif
