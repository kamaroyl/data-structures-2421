#include "DeletePictureMenu.hpp"
#include "../../Data/Picture.hpp"

DeletePictureMenu::DeletePictureMenu() {
    this->picture = nullptr;
}

void DeletePictureMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Delete Picture");
    std::cout << std::endl;
    std::cout << "Are you sure you want to delete: " << std::endl;
    std::cout << this->picture << " ?" << std::endl; 
    std::cout << "S) Confirm" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string DeletePictureMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(input == "B" || input == "b") {
            input = "B";
            break;
        }
         
        if(input == "Q" || input == "q") {
             input = "Q";
             break;
        }

        if(input == "S" || input == "s") {
            input = "S";
            break;
        }
        
        std::cout << "Please enter S, B or Q only" << std::endl;

        
    }
    return input;
   
}

void DeletePictureMenu::setPicture(Picture* picture) {
    this->picture = picture;
}

Picture* DeletePictureMenu::getPicture() {
    return this->picture;
}

std::string DeletePictureMenu::confirmMenu() {
    std::cout << "Are you sure you want to delete picture ?" << std::endl;
    std::cout << this->picture << std::endl;
    std::cout << "Y/n" << std::endl;
    std::string input = "";
    while(true) {
        std::getline(std::cin, input);
        if(input.empty() || input != "Y" || input != "n") {
            std::cout << "Please enter \"Y\" or \"n\"" << std::endl;
            continue;
        }
        return input;
    }
    
}

void DeletePictureMenu::clear() {
    this->picture = nullptr;
}
