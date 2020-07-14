#include "EditActorMenu.hpp"

EditActorMenu::EditActorMenu() {
    this->index = 0;
    this->year = "";
    this->award = "";
    this->winner = "";
    this->name = "";
    this->film = "";
    this->actor = nullptr;
}

void EditActorMenu::setIndex(unsigned int index) {
    this->index = index;
}

void EditActorMenu::setActor(Actor* actor) {
    this->actor = actor;
    this->year = std::to_string(actor->getYear());
    this->award = actor->getAward();
    this->winner = std::to_string(actor->getWinner());
    this->name = actor->getName();
    this->film = actor->getFilm();
}

void EditActorMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Edit Actor");
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

unsigned int EditActorMenu::getIndex() {
    return this->index;
}

std::string EditActorMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        
        std::getline(std::cin, input);

        if(input == "Y" || input == "y") {
            this->setYear();
            return "Y";
        }
        
        if(input == "A" || input == "a") {
            this->setAward();
            return "A";
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
            if(this->submit()) {
                this->actor->setYear(this->year);
                this->actor->setAward(this->award);
                this->actor->setWinner(this->winner);
                this->actor->setName(this->name);
                this->actor->setFilm(this->film);
                return "S";  
            }                                 
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

bool EditActorMenu::submit() {
    std::cout << "Would you like to submit?" << std::endl;
    std::cout << "Actor: { Year:" << this->year << " Award:" << this->award << " Winner:" << this->winner << " Name:" << this->name << " Film:" << this->film << " }" << std::endl;
    std::cout << "Y/n" << std::endl;
    
    std::string input = "";    
    while(true) {
        std::getline(std::cin, input);
        if(input.empty() || input != "Y" || input != "n") {
            std::cout << "Please enter \"Y\" or \"n\"" << std::endl;
            continue;
        }
        return input == "Y";
    }

}

void EditActorMenu::setYear() {
    std::string input = "";

    while(true) {
        std::cout << "Please enter a year" << std::endl;
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

void EditActorMenu::setAward() {
    std::string input = "";
    
    while(true) {
        std::cout << "Please enter an award name" << std::endl;
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->award = input;
        break;
    }

}

void EditActorMenu::setWinner() {
    std::string input = "";
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

void EditActorMenu::setName() {
    std::string input = "";
    
    while(true) {
        std::cout << "Please enter an actor name" << std::endl;
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->name = input;
        break;
    }

}

void EditActorMenu::setFilm() {
    std::string input = "";
    
    while(true) {
        std::cout << "Please enter a film name" << std::endl;
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->film = input;
        break;
    }

}

void EditActorMenu::clear() {
    this->index = 0;
    this->year = "";
    this->award = "";
    this->winner = "";
    this->name = "";
    this->film = "";
    this->actor = nullptr;
}
