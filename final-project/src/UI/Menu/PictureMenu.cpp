#include "PictureMenu.hpp"
#include "MenuBase.hpp"

PictureMenu::PictureMenu() {
}

void PictureMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Picture Menu");
    std::cout << std::endl;
    std::cout << "A) Add " << std::endl;
    std::cout << "E) Edit (ID)" << std::endl;
    std::cout << "S) Search" << std::endl;
    std::cout << "D) Delete (ID)" << std::endl;
    std::cout << "F) To File" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string PictureMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        std::getline(std::cin, input);

        if(input == "A" || input == "a") {
            input = "A";
            break;
        }
        
        if(input == "E" || input == "e") {
            input = "E";
            break;
        }
        
        if(input == "S" || input == "s") {
            input = "S";
            break;
        }

        if(input == "D" || input == "d") {
            input = "D";
            break;
        }

        if(input == "F" || input == "f") {
            input = "F";
            break;
        }

        if(input == "B" || input == "b") {
            input = "B";
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


