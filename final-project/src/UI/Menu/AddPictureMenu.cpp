#include "AddPictureMenu.hpp"
#include "MenuBase.hpp"

AddPictureMenu::AddPictureMenu() {
    this->name = "";
    this->year = "";
    this->nominations = "";
    this->rating = "";
    this->duration = "";
    this->genre1 = "";
    this->genre2 = "";
    this->release = "";
    this->metacritic = "";
    this->synopsis = "";
    this->index = 0;
}

void AddPictureMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Add Picture");
    std::cout << std::endl;
    std::cout << "Y) Year: " << this->year << std::endl;
    std::cout << "N) Name: " << this->name << std::endl;
    std::cout << "T) Nominations: " << this->nominations << std::endl;
    std::cout << "4) Rating: " << this->rating << std::endl;
    std::cout << "D) Duration: " << this->duration << std::endl;
    std::cout << "1) Genre1: " << this->genre1 << std::endl;
    std::cout << "2) Genre2: " << this->genre2 << std::endl;
    std::cout << "L) Release: " << this->release << std::endl;
    std::cout << "M) Metacritic: " << this->metacritic << std::endl;
    std::cout << "3) Synopsis: " << this->synopsis << std::endl;
    std::cout << "S) Submit" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

std::string AddPictureMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        std::getline(std::cin, input);
        
        if(input == "Y" || input == "y") {
            input = "Y";
            this->setYear();
        }
        
        if(input == "N" || input == "n") {
            input = "N";
            this->setName();
        } 

        if(input == "T" || input == "t") {
            input = "T";
            this->setNominations();
        }
        
        if(input == "4") {
            input = "4";
            this->setRating();
        }

        if(input == "D" || input == "d") {
            input = "D";
            this->setDuration();
        }
        
        if(input == "1") {
            this->setGenre1();
        }

        if(input == "2") {
            this->setGenre2();
        }

        if(input == "L" || input == "l") {
            input = "L";
            this->setRelease();
        }

        if(input == "M" || input == "m") {
            input = "M";
            this->setMetacritic();
        }

        if(input == "3") {
            input = "3";
            this->setSynopsis();
        }
        
        if(input == "S" || input == "s") {
            if(this->submit()) return "S";
        }
        
        if(input == "B" || input == "b") {
            return "B";
        }
        
        if(input == "Q" || input == "q") {
            return "Q";
        }
        
        this->printMenu();
        if(input != "Y" && input != "N" && input != "T" && input != "R" && input != "D" && input != "1" && input != "2" && input != "L" && input != "M" && input != "P") {
            std::cout << "Your input " << input << "is invalid" << std::endl;
            std::cout << "Please enter a valid answer" << std::endl;
        } 
        
    }
    return input;
}

Picture* AddPictureMenu::getPicture() {
    return new Picture(this->index, this->name, this->year, this->nominations, this->rating, this->duration, this->genre1, this->genre2, this->release, this->metacritic, this->synopsis);
}

bool AddPictureMenu::submit() {
    std::cout << "Would you like to submit?" << std::endl;
    std::cout << "Picture: { Name: " << this->name << " Year: " << this->year << " Nominations: " << this->nominations << " Rating: " << this->rating << " Duration: " << this->duration << " Genre1: " << this->genre1 << " Genre2: " << this->genre2 << " Release: " << this->release << " Metacritic: " << this->metacritic << " Synopsis " << this->synopsis << " }" << std::endl;
    std::cout <<"Y/n" << std::endl;
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
void AddPictureMenu::clear() {
    this->index = 0;
    this->name = "";
    this->year = "";
    this->nominations = "";
    this->rating = "";
    this->duration = "";
    this->genre1 = "";
    this->genre2 = "";
    this->release = "";
    this->metacritic = "";
    this->synopsis = "";
}

void AddPictureMenu::setIndex(unsigned int index) {
    this->index = index;
}

void AddPictureMenu::setName() {
    std::string input = "";
    std::cout << "Please enter the name: " << std::endl;    
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->name = input;
        break;
    }
}

void AddPictureMenu::setYear() {
    std::string input = "";
    std::cout << "Please enter a year: " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter a numeric value; " << input << " is not a numeric value." << std::endl;
            continue;
        }
        this->year = input;
        break;
    }
}

void AddPictureMenu::setNominations() {
    std::string input = "";
    std::cout << "Please enter the number of nominations: " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter a numeric value; " << input << " is not a numeric value." << std::endl;
            continue;
        }
        this->nominations = input;
        break;
    }

}

void AddPictureMenu::setRating() {
    std::string input = "";
    std::cout << "Please enter a the float value rating of the picture:" << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isFloat(&input)) {
            std::cout << "Please enter a float value; " << input << " is not fit to be a float" << std::endl;
            continue;
        }

        float result = std::stof(input);

        if(result < 0.0 || result > 10.0) {
            std::cout << "Please enter a float value between 0.0 and 10.0" << std::endl;
            continue;
        }
        
        this->rating = input;
        break;
    }
}

void AddPictureMenu::setDuration() {
    std::string input = "";
    std::cout << "Please enter the duration of the picture: " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter a numeric value; " << input << " is not a numeric value." << std::endl;
            continue;
        }
        this->duration = input;
        break;
    }

}

void AddPictureMenu::setGenre1() {
    std::cout << "Please pick a genre" << std::endl;
    this->printGenre();
    std::string input = "";
    int result = 0;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter the number of the corresponding genre" << std::endl;
            continue;
        }
        result = std::stoi(input);
        if( result < 1 || result > 13) {
            std::cout << "Please enter a number between 1 and 13 inclusive. " << input << " is not within the bounds" << std::endl;
            continue;
        }
    }

    if(result == 1) {
        this->genre1 = "ACTION";
    } else if(result == 2) {
        this->genre1 = "ADVENTURE";
    } else if(result == 3) {
        this->genre1 = "BIOGRAPHY";
    } else if(result == 4) {
        this->genre1 = "COMEDY";
    } else if(result == 5) {
        this->genre1 = "CRIME";
    } else if(result == 6) {
        this->genre1 = "DRAMA";
    } else if(result == 7) {
        this->genre1 = "FAMILY";
    } else if(result == 8) {
        this->genre1 = "FILM-NOIR";
    } else if(result == 9) {
        this->genre1 = "MUSICAL";
    } else if(result == 10) {
        this->genre1 = "MYSTERY";
    } else if(result == 11) {
        this->genre1 = "ROMANCE";
    } else if(result == 12) {
        this->genre1 = "WAR";
    } else if(result == 13) {
        this->genre1 = "WESTERN";
    }
      
}

void AddPictureMenu::setGenre2() {
    std::cout << "Please pick a genre" << std::endl;
    this->printGenre();
    std::string input = "";
    int result = 0;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter the number of the corresponding genre" << std::endl;
            continue;
        }
        result = std::stoi(input);
        if( result < 1 || result > 13) {
            std::cout << "Please enter a number between 1 and 13 inclusive. " << input << " is not within the bounds" << std::endl;
            continue;
        }
    }

    if(result == 1) {
        this->genre2 = "ACTION";
    } else if(result == 2) {
        this->genre2 = "ADVENTURE";
    } else if(result == 3) {
        this->genre2 = "BIOGRAPHY";
    } else if(result == 4) {
        this->genre2 = "COMEDY";
    } else if(result == 5) {
        this->genre2 = "CRIME";
    } else if(result == 6) {
        this->genre2 = "DRAMA";
    } else if(result == 7) {
        this->genre2 = "FAMILY";
    } else if(result == 8) {
        this->genre2 = "FILM-NOIR";
    } else if(result == 9) {
        this->genre2 = "MUSICAL";
    } else if(result == 10) {
        this->genre2 = "MYSTERY";
    } else if(result == 11) {
        this->genre2 = "ROMANCE";
    } else if(result == 12) {
        this->genre2 = "WAR";
    } else if(result == 13) {
        this->genre2 = "WESTERN";
    }
   
}

void AddPictureMenu::setRelease() {
    std::cout << "Please pick a release month" << std::endl;
    this->printMonths();
    std::string input = "";
    int result = 0;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter the number of the corresponding Month" << std::endl;
            continue;
        }
        result = std::stoi(input);
        if( result < 1 || result > 13) {
            std::cout << "Please enter a number between 1 and 12 inclusive. " << input << " is not within the bounds" << std::endl;
            continue;
        }
    }

    if(result == 1) {
        this->release = "JANUARY";
    } else if(result == 2) {
        this->release = "FEBRUARY";
    } else if(result == 3) {
        this->release = "MARCH";
    } else if(result == 4) {
        this->release = "APRIL";
    } else if(result == 5) {
        this->release = "MAY";
    } else if(result == 6) {
        this->release = "JUNE";
    } else if(result == 7) {
        this->release = "JULY";
    } else if(result == 8) {
        this->release = "AUGUST";
    } else if(result == 9) {
        this->release = "SEPTEMBER";
    } else if(result == 10) {
        this->release = "OCTOBER";
    } else if(result == 11) {
        this->release = "NOVEMBER";
    } else if(result == 12) {
        this->release = "DECEMBER";
    } 
}

void AddPictureMenu::setMetacritic() {
    std::string input = "";
    int result = 0;
    std::cout << "Please enter the metacritic score of the picture: " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(!this->isNumber(&input)) {
            std::cout << "Please enter a numeric value; " << input << " is not a numeric value." << std::endl;
            continue;
        }
        result = std::stoi(input);
        if( result < 1 || result > 100) {
            std::cout << "Please enter a number between 1 and 100 inclusive. " << input << " is not within the bounds" << std::endl;
            continue;
        }
     
        this->duration = result;
        break;
    }

    this->metacritic = input;
}

void AddPictureMenu::setSynopsis() {
    std::string input = "";
    std::cout << "Please enter a synopsis for the picture " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->synopsis = input;
        break;
    }
}

void AddPictureMenu::printGenre() {

    std::cout << "1) Action " << std::endl;
    std::cout << "2) Adventure " << std::endl;
    std::cout << "3) Biography " << std::endl;
    std::cout << "4) Comedy " << std::endl;
    std::cout << "5) Crime " << std::endl;
    std::cout << "6) Drama " << std::endl;
    std::cout << "7) Family " << std::endl; 
    std::cout << "8) Film-Noir " << std::endl;
    std::cout << "9) Musical " << std::endl;
    std::cout << "10) Mystery " << std::endl;
    std::cout << "11) Romance " << std::endl;
    std::cout << "12) War " << std::endl;
    std::cout << "13) Western " << std::endl;
}

void AddPictureMenu::printMonths() {

    std::cout << "1) January " << std::endl;
    std::cout << "2) February " << std::endl;
    std::cout << "3) March " << std::endl;
    std::cout << "4) April " << std::endl;
    std::cout << "5) May " << std::endl;
    std::cout << "6) June " << std::endl;
    std::cout << "7) July " << std::endl; 
    std::cout << "8) August " << std::endl;
    std::cout << "9) September " << std::endl;
    std::cout << "10) October " << std::endl;
    std::cout << "11) November " << std::endl;
    std::cout << "12) December " << std::endl;

}

