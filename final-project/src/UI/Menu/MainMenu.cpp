#include "MainMenu.hpp"
#include "MenuBase.hpp"
MainMenu::MainMenu(){ 
}

void MainMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Main Menu");
    std::cout << std::endl;
    std::cout << "A) Actor" << std::endl;
    std::cout << "P) Picture" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string MainMenu::getUserInfo() {
    std::string input = "";
    while(true) {
     
        std::getline(std::cin, input);
        if(input == "A" || input == "a"){
            input = "A";
            break;
        }
        if(input == "P" || input == "p") {
            input = "P";
            break;
        }
        if(input == "Q" || input == "q") {
            input = "Q";
            break;
        }
        this->printMenu();
        std::cout << "your input " << input << " is invalid" << std::endl;
        std::cout << "Please enter a valid answer" << std::endl;
    }
    return input;
}
