#include "ToFileActorMenu.hpp"
#include "MenuBase.hpp"

ToFileActorMenu::ToFileActorMenu() {
    this->filePath = "";
}

void ToFileActorMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Actor To File");
    std::cout << std::endl;
    std::cout << "Please enter a file path or Back/Quit" << std::endl;
    std::cout << "S) Submit" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string ToFileActorMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        if(input == "S" || input == "s") {
            return "S";
        }
        if(input == "B" || input == "b") {
            return "B";
        } else if(input == "Q" || input == "q") {
            return "Q";   
        }
        if(input.empty()) continue;
        return input;
    }
}

void ToFileActorMenu::clear() {
    this->filePath = "";
}

std::string ToFileActorMenu::getFilePath() {
    return this->filePath;
}

