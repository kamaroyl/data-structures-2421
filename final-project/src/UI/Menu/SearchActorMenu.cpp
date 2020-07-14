#include "SearchActorMenu.hpp"
SearchActorMenu::SearchActorMenu() {
    this->year = "";
    this->award = "";
    this->winner = "";
    this->name = "";
    this->film = "";
}

void SearchActorMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Search Actors");
    
    std::cout << std::endl;
    std::cout << "Y) Filter Actors by year" << std::endl;
    std::cout << "A) Filter Actors by award" << std::endl;
    std::cout << "W) Filter Actors by winner" << std::endl;   
    std::cout << "N) Filter Actors by name" << std::endl;
    std::cout << "F) Filter Actors by film" << std::endl;
    std::cout << "P) Print Actors with current filters (prints all if no filters applied)" << std::endl;
    std::cout << "R) Remove last filter applied" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string SearchActorMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        std::getline(std::cin, input);
        
        if(input == "Y" || input == "y") {
            this->setYearFilter();
        }
        
        if(input == "A" || input == "a") {
            this->setAwardFilter();
        }

        if(input == "W" || input == "w") {
            this->setWinnerFilter();
        }

        if(input == "N" || input == "n") {
            this->setNameFilter();
        }

        if(input == "F" || input == "f") {
            this->setFilmFilter();
        }
        
        if(input == "P" || input == "p") {
            input = "P";
            break;
        }

        if(input == "B" || input == "b") {
            input = "B";
            break;
        }

        if(input == "R" || input == "r") {
            input = "R";
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

void SearchActorMenu::setYearFilter() {
    std::string input = "";
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

        this->year = result;
        break;
    }
}

void SearchActorMenu::setAwardFilter() {
    std::string input = "";
    
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->award = input;
        break;
    }
}

void SearchActorMenu::setWinnerFilter() {
    std::string input = "";
    std::cout << "0) False" << std::endl;
    std::cout << "1) True" << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input != "1" || input != "0") {
            std::cout << "please enter 0 or 1" << std::endl;
            continue;
        }
        
        this->winner = input;
        break;
    }
}

void SearchActorMenu::setNameFilter() {
    std::string input = "";
    
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->name = input;
        break;
    }
}

void SearchActorMenu::setFilmFilter() {
    std::string input = "";
    
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->film = input;
        break;
    }
}

std::string SearchActorMenu::getYear() {
    return this->year;
}

std::string SearchActorMenu::getAward() {
    return this->award;
}

std::string SearchActorMenu::getWinner() {
    return this->winner;
}

std::string SearchActorMenu::getName() {
    return this->name;
}

std::string SearchActorMenu::getFilm() {
    return this->film;
}

