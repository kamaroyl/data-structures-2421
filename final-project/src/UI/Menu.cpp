#include "Menu.hpp"

Menu::Menu() {
        
}

void Menu::askForActorFileInput() {
    std::cout << "Please give a valid file path for the actor csv" << std::endl;
}

void Menu::askForPictureFileInput() {
    std::cout << "Please give a valid file path for the actor csv" << std::endl;
}

void Menu::invalidFilePath(std::string fp) {
    std::cout << "The file path you have given" << std::endl;
    std::cout << fp << std::endl;
    std::cout << "is invalid" << std::endl;
}

void Menu::mainMenu() {
    std::cout << "1) Actors" << std::endl;
    std::cout << "2) Pictures" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

void Menu::itemMenu() {
    std::cout << "1) " << std::endl;
    std::cout << "2) " << std::endl;
    std::cout << "A) Add" << std::endl;
    std::cout << "E) Edit" << std::endl;
    std::cout << "D) Delete" << std::endl;
    std::cout << "T) To File" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

void Menu::addFilterActor() {
    std::cout << "1) index" << std::endl;
    std::cout << "2) year" << std::endl;
    std::cout << "3) award" << std::endl;
    std::cout << "4) winner" << std::endl;
    std::cout << "5) name" << std::endl;
    std::cout << "6) film" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

void Menu::printActiveFiltersActor(ActorFilter filter) {
    filter.printActive();
}

void Menu::printActiveFiltersPicture(PictureFilter filter) {
    filter.printActive();
}

void Menu::addFilterPicture() {
    std::cout << "1) index" << std::endl;
    std::cout << "2) name" << std::endl;
    std::cout << "3) year" << std::endl;
    std::cout << "4) nominations" << std::endl;
    std::cout << "5) rating" << std::endl;
    std::cout << "6) duration" << std::endl;
    std::cout << "7) genre1" << std::endl;
    std::cout << "8) genre2" << std::endl;
    std::cout << "9) release" << std::endl;
    std::cout << "10) metacritic" << std::endl;
    std::cout << "11) synopsis" << std::endl;
    std::cout << "B) Back" << std::endl;
    std::cout << "Q) Quit" << std::endl;
}

void Menu::printActiveFilterPicture(PictureFilter filter) {
    filter.printActive();
}

void Menu::printAddPictureName() {
    std::cout << "Please enter a name for the picture" << std::endl;
}

void Menu::printAddPictureYear() {
    std::cout << "Please enter the year the picture was nominated" << std::endl;
}

void Menu::printAddPictureNominations() {
    std::cout << "Please enter the number of nominations for the picture" << std::endl;
}

void Menu::printAddPictureRating() {
    std::cout << "Please enter the rating of the picture" << std::endl;
}

void Menu::printAddPictureDuration() {
    std::cout << "Please enter the duration of the picture" << std::endl;
}

void Menu::printAddPictureMetacritic() {
    std::cout << "Please enter a number between 0 and 100 for the metacritic score" << std::endl;
}

void Menu::printAddPictureSynopsis() {
    std::cout << "Please enter a synopsis for the picture" << std::endl;
}

void Menu::printAddPictureGenre() {
    std::cout << "Please enter two genres" << std::endl;
    std::cout << "1) Action" << std::endl;
    std::cout << "2) Adventure" << std::endl;
    std::cout << "3) Biography" << std::endl;
    std::cout << "4) Comedy" << std::endl;
    std::cout << "5) Crime" << std::endl;
    std::cout << "6) Drama" << std::endl;
    std::cout << "7) Family" << std::endl;
    std::cout << "8) Film Noir" << std::endl;
    std::cout << "9) Musical" << std::endl;
    std::cout << "10) Mystery" << std::endl;
    std::cout << "11) Romance" << std::endl;
    std::cout << "12) War" << std::endl;
    std::cout << "13) Western" << std::endl;
}

void Menu::printMonth() {
    std::cout << "Please enter the month of release for the picture" << std::endl;
    std::cout << "1) January" << std::endl;
    std::cout << "2) February" << std::endl;
    std::cout << "3) March" << std::endl;
    std::cout << "4) April" << std::endl;
    std::cout << "5) May" << std::endl;
    std::cout << "6) June" << std::endl;
    std::cout << "7) July" << std::endl;
    std::cout << "8) August" << std::endl;
    std::cout << "9) September" << std::endl;
    std::cout << "10) October" << std::endl;
    std::cout << "11) November" << std::endl;
    std::cout << "12) December" << std:endl;
}

void Menu::removePicture(Picture picture) {
    std::cout << "are you sure you would like to remove the picture:" << std::endl;
    picture.print();
}

void Menu::removeActor(Actor actor) {
    std::cout << "Are you sure you would like to remove the actor: " >> std::endl;
    actor.print();
}
