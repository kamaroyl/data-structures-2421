#include "AddActorMenu.hpp"
#include "MenuBase.hpp"

AddActorMenu::AddActorMenu() { 
    this->index = 0;   
    this->year = "";
    this->award = "";
    this->winner = "";
    this->name = "";
    this->film = "";
    
}

void AddActorMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Add Actor");
    std::cout << std::endl;
    std::cout << "Y) Year: " << this->year << std::endl;
    std::cout << "A) Award: " << this->award <<std::endl;
    std::cout << "W) Winner: " << this->winner << std::endl;
    std::cout << "N) Name: " << this->name << std::endl;
    std::cout << "F) Film: " << this->film << std::endl;
    std::cout << "S) Submit" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string AddActorMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        
        std::getline(std::cin, input);

        if(input == "Y" || input == "y") {
            this->setYear();
        }
        
        if(input == "A" || input == "a") {
            this->setAward();
        }

        if(input == "W" || input == "w") {
            this->setWinner();
        }

        if(input == "N" || input == "n") {
            this->setName();
        }

        if(input == "F" || input == "f") {
            this->setFilm();
        }
        
        if(input == "S" || input == "s") {
            if(this->submit()) return "S";                                   
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
        if(input != "Y" && input != "A" && input != "W" && input != "N" && input != "F") {
            std::cout << "your input " << input << " is invalid" << std::endl;
            std::cout << "Please enter a valid answer" << std::endl;
        }
    }
    return input;
}

Actor* AddActorMenu::getActor() {
    return new Actor(this->index, this->year, this->award, this->winner, this->name, this->film);
}

void AddActorMenu::setYear() {
    std::string input = "";
    std::cout << "Please enter a year: " << std::endl; 
    while(true) {

        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter a numeric value; " << input << " is not a numeric value." << std::endl;
            continue;
        }

        int result = std::stoi(input);

        if(result < 1900 || result > 10000) {
            std::cout << "Please enter a numeric value between 1900 and 10000" << std::endl;
            continue;
        }

        this->year = input;
        break;
    }
}

void AddActorMenu::setAward() {
    std::string input = "";
    std::cout << "Please enter an award: " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->award = input;
        break;
    }
}

void AddActorMenu::setWinner() {
    std::string input = "";
    std::cout << "Please enter winner: " << std::endl;
    std::cout << "0) False" << std::endl;
    std::cout << "1) True" << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input != "1" && input != "0") {
            std::cout << "please enter 0 or 1" << std::endl;
            continue;
        }
        
        this->winner = input;
        break;
    }
}

void AddActorMenu::setName() {
    std::string input = "";
    std::cout << "Please enter Name: " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->name = input;
        break;
    }
}

void AddActorMenu::setFilm() {
    std::string input = "";
    std::cout << "Please enter film: " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->film = input;
        break;
    }
}

void AddActorMenu::setIndex(unsigned int index) {
    this->index = index;
}

bool AddActorMenu::submit() {
    std::cout << "Would you like to submit?" << std::endl;
    std::cout << "Actor: { Year:" << this->year << " Award:" << this->award << " Winner:" << this->winner << " Name:" << this->name << " Film:" << this->film << " }" << std::endl;
    std::cout << "Y/n" << std::endl;
    
    std::string input = "";    
    while(true) {
        std::getline(std::cin, input);
        if(input.empty() || (input != "Y" && input != "n")) {
            std::cout << "Please enter \"Y\" or \"n\"" << std::endl;
            continue;
        }
        return input == "Y";
    }
}

void AddActorMenu::clear() {
    this->index=0;
    this->year = "";
    this->award = "";
    this->winner = "";
    this->name = "";
    this->film = "";
}
