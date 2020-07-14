#include "Picture.hpp"

Picture::Picture(unsigned int index,
                 std::string name, 
                 std::string year, 
                 std::string nominations, 
                 std::string rating, 
                 std::string duration, 
                 std::string genre1, 
                 std::string genre2, 
                 std::string release, 
                 std::string metacritic, 
                 std::string synopsis) {
    this->index = index;
    this->name = name;
    this->year = (unsigned short) std::stoi(year);
    if(nominations == "-") nominations = "0";
    this->nominations = (unsigned short) std::stoi(nominations);
    this->rating = std::stof(rating);
    this->duration = (unsigned short) std::stoi(duration);
    this->genre1 = Genre(genre1);
    this->genre2 = Genre(genre2);
    this->release = Month(release);
    if(metacritic == "") metacritic = "0";
    this->metacritic = (unsigned short) std::stoi(metacritic);
    this->synopsis = synopsis;
}

Picture::Picture() {
}

unsigned int Picture::getIndex() {
    return this->index;
}

std::string Picture::getName() {
    return this->name;
}

unsigned short Picture::getYear() {
    return this->year;
}    

unsigned short Picture::getNominations() {
    return this->nominations;
}

float Picture::getRating() {
    return this->rating;
}

unsigned short Picture::getDuration() {
    return this->duration;
}

Genre Picture::getGenre1() {
    return this->genre1;
}

Genre Picture::getGenre2() {
    return this->genre2;
}

Month Picture::getRelease() {
    return this->release;
}

unsigned short Picture::getMetacritic() {
    return this->metacritic;
}

std::string Picture::getSynopsis() {
    return this->synopsis;
}

void Picture::setIndex(std::string index) {
    this->index = (unsigned int) std::stoi(index); 
}

void Picture::setName(std::string) {
    this->name = name;
}

void Picture::setYear(std::string year) {
    this->year = (unsigned short) std::stoi(year);
}

void Picture::setNominations(std::string nominations) {
    this->nominations = (unsigned short) std::stoi(nominations);
}

void Picture::setRating(std::string rating) {
    this->rating = std::stof(rating);
}

void Picture::setDuration(std::string duration) {
    this->duration = (unsigned short) std::stoi(duration);
}

void Picture::setGenre1(std::string genre1){
    this->genre1 = Genre(genre1);
}

void Picture::setGenre2(std::string genre2) {
    this->genre2 = Genre(genre2);
}

void Picture::setRelease(std::string release) {
    this->release = Month(release);
}

void Picture::setMetacritic(std::string metacritic) {
    this->metacritic = (unsigned short) std::stoi(metacritic);
}

void Picture::setSynopsis(std::string synopsis) {
    this->synopsis = synopsis;
}


void Picture::print() {
    std::cout << "Picture: { ";
    std::cout << "index: " << this->index << ", "; 
    std::cout << "name: " << this->name << ", ";
    std::cout << "year: " << this->year << ", ";
    std::cout << "nominations: " << this->nominations << ", ";
    std::cout << "rating: " << this->rating << ", ";
    std::cout << "duration: " << this->duration << ", ";
    std::cout << "genre1: " << this->genre1.toString() << ", ";
    std::cout << "genre2: " << this->genre2.toString() << ", ";
    std::cout << "release: " << this->release.toString() << ", ";
    std::cout << "metacritic: " << this->metacritic << ", ";
    std::cout << "synopsis: " << this->synopsis;
    std::cout << " }" << std::endl;
}

std::string Picture::toCsvFormat() {
    std::stringstream ss;
    /*name,year,nominations,rating,duration,genre1,genre2,release,metacritic,synopsis*/
    ss << this->name << ",";
    ss << this->year << ",";
    ss << this->nominations << ",";
    ss << this->rating << ",";
    ss << this->duration << ",";
    ss << this->genre1.toString() << ",";
    ss << this->genre2.toString() << ",";
    ss << this->release.toString() << ",";
    ss << this->metacritic << ",";
    ss << this->synopsis;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, Picture& picture) {
    os << "Picture: { ";
    os << "index: " << picture.index << ", "; 
    os << "name: " << picture.name << ", ";
    os << "year: " << picture.year << ", ";
    os << "nominations: " << picture.nominations << ", ";
    os << "rating: " << picture.rating << ", ";
    os << "duration: " << picture.duration << ", ";
    os << "genre1: " << picture.genre1.toString() << ", ";
    os << "genre2: " << picture.genre2.toString() << ", ";
    os << "release: " << picture.release.toString() << ", ";
    os << "metacritic: " << picture.metacritic << ", ";
    os << "synopsis: " << picture.synopsis;
    os << " }" << std::endl;
    return os;
}
