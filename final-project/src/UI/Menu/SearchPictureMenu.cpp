#include "SearchPictureMenu.hpp"

SearchPictureMenu::SearchPictureMenu() {
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

std::string SearchPictureMenu::getName() {
    return this->name;
}

std::string SearchPictureMenu::getYear() {
    return this->year;
}

std::string SearchPictureMenu::getNominations() {
    return this->nominations;
}

std::string SearchPictureMenu::getRating() {
    return this->rating;
}

std::string SearchPictureMenu::getDuration() {
    return this->duration;
}

std::string SearchPictureMenu::getGenre1() {
    return this->genre1;
}

std::string SearchPictureMenu::getGenre2() {
    return this->genre2;
}

std::string SearchPictureMenu::getRelease() {
    return this->release;
}

std::string SearchPictureMenu::getMetacritic() {
    return this->metacritic;
}

std::string SearchPictureMenu::getSynopsis() {
    return this->synopsis;
}
void SearchPictureMenu::printMenu() {
    this->clearScreen();
    this->printHeader("Search Pictures");
    
    std::cout << std::endl;
    std::cout << "Y) Filter Pictures by Year " << std::endl;
    std::cout << "N) Filter Pictures by Name "  << std::endl;
    std::cout << "T) Filter Pictures by Nominations " << std::endl;
    std::cout << "4) Filter Pictures by Rating "  << std::endl;
    std::cout << "D) Filter Pictures by Duration " << std::endl;
    std::cout << "1) Filter Pictures by Genre1 " << std::endl;
    std::cout << "2) Filter Pictures by Genre2 " << std::endl;
    std::cout << "L) Filter Pictures by Release " << std::endl;
    std::cout << "M) Filter Pictures by Metacritic " << std::endl;
    std::cout << "3) Filter Pictures by Synopsis " << std::endl;
    std::cout << "P) Print Pictures with current filters " << std::endl;
    std::cout << "R) Remove last filter applied" << std::endl;
    std::cout << "S) Submit" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;

}

std::string SearchPictureMenu::getUserInfo() {
    std::string input = "";
    while(true) {
        std::getline(std::cin, input);
        
        if(input == "Y") {
            this->setYearFilter();
        }

        if(input == "N") {
            this->setNameFilter();
        }

        if(input == "T") {
            this->setNominationsFilter();
        }

        if(input == "4") {
            this->setRatingFilter();
        }

        if(input == "D") {
            this->setDurationFilter();
        }

        if(input == "1") {
            this->setGenre1Filter();
        }

        if(input == "2") {
            this->setGenre2Filter();
        }

        if(input == "L") {
            this->setReleaseFilter();
        }

        if(input == "M") {
            this->setMetacriticFilter();
        }

        if(input == "3") {
            this->setSynopsisFilter();
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
        
    }
    return input;
}

void SearchPictureMenu::setYearFilter() {
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

void SearchPictureMenu::setNameFilter() {
    std::string input = "";
    
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->name = input;
        break;
    }

}

void SearchPictureMenu::setNominationsFilter() {
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

void SearchPictureMenu::setRatingFilter() {
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

void SearchPictureMenu::setDurationFilter() {
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


void SearchPictureMenu::clear() {
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

void SearchPictureMenu::setGenre1Filter() {
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

void SearchPictureMenu::setGenre2Filter() {
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

void SearchPictureMenu::printGenre() {

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

void SearchPictureMenu::printMonths() {

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

void SearchPictureMenu::setReleaseFilter() {
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

void SearchPictureMenu::setMetacriticFilter() {
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

void SearchPictureMenu::setSynopsisFilter() {
    std::string input = "";
    std::cout << "Please enter a synopsis for the picture " << std::endl;
    while(true) {
        std::getline(std::cin, input);
        if(input.empty()) continue;
        this->synopsis = input;
        break;
    }
}

