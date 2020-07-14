#include "DeleteActorMenu.hpp"
#include "../../Data/Actor.hpp"

DeleteActorMenu::DeleteActorMenu() {
    this->actor = nullptr;
}

void DeleteActorMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Edit Actor");
    std::cout << std::endl;
    std::cout << "Are you sure you want to delete: " << std::endl;
    std::cout << this->actor << " ?" << std::endl; 
    std::cout << "S) Confirm" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string DeleteActorMenu::getUserInfo() {
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

void DeleteActorMenu::setActor(Actor* actor) {
    this->actor = actor;
}

Actor* DeleteActorMenu::getActor() {
    return this->actor;
}

std::string DeleteActorMenu::confirmMenu() {
    std::cout << "Are you sure you want to delete actor ?" << std::endl;
    std::cout << this->actor << std::endl;
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


void DeleteActorMenu::clear() {
    this->actor = nullptr;
}
