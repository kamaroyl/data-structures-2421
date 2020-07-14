#include "ToFilePictureMenu.hpp"
#include "MenuBase.hpp"

ToFilePictureMenu::ToFilePictureMenu() {
    this->filePath = "";
}

void ToFilePictureMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Picture To File");
    std::cout << std::endl;
    std::cout << "Please enter a file path or Back/Quit" << std::endl;
    std::cout << "S) Submit" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string ToFilePictureMenu::getUserInfo() {
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

void ToFilePictureMenu::clear() {
    this->filePath = "";
}

std::string ToFilePictureMenu::getFilePath() {
    return this->filePath;
}

