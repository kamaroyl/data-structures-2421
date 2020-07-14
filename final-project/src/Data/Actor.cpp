#include "Actor.hpp"
#include "../../lib/util/StringsUtil.hpp"
Actor::Actor(unsigned int index, std::string year, std::string award, std::string winner, std::string name, std::string film) {
    this->index = index;
    this->year = (unsigned short) std::stoi(year);
    this->award = award;
    this->winner = stringToBool(winner);
    this->name = name;
    this->film = film;
}

Actor::Actor() {
}

unsigned int Actor::getIndex() {
    return this->index;
}

unsigned short Actor::getYear() {
    return this->year;
}

std::string Actor::getAward() {
    return this->award;
}

bool Actor::getWinner() {
    return this->winner;
}

std::string Actor::getName() {
    return this->name;
}

std::string Actor::getFilm() {
    return this->film;
}

void Actor::setIndex(unsigned int index) {
    this->index = index;
}

void Actor::setYear(std::string year) {
    this->year = (unsigned short) std::stoi(year);
}

void Actor::setAward(std::string award) {
    this->award = award;
}

void Actor::setWinner(std::string winner) {
    this->winner = stringToBool(winner);
}

void Actor::setName(std::string name) {
    this->name = name;
}

void Actor::setFilm(std::string film) {
    this->film = film;
}

void Actor::print() {
    std::cout << "Actor: { ";
    std::cout << "index: " << this->index << ", ";
    std::cout << "year: " << this->year << ", ";
    std::cout << "award: " << this->award << ", ";
    std::cout << "winner: " << boolToString(this->winner) << ", ";
    std::cout << "name: " << this->name << ", ";
    std::cout << "film: " << this->film;
    std::cout << " }" << std::endl;
}

/*year,award,winner,name,film */
std::string Actor::toCsvFormat() {
    std::stringstream ss;
    ss << this->year << ",";
    ss << this->award << ",";
    ss << this->winner << ",";
    ss << this->name << ",";
    ss << this->film;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, Actor& actor) {
    os << "Actor: { ";
    os << "index: " << actor.index << ", ";
    os << "year: " << actor.year << ", ";
    os << "award: " << actor.award << ", ";
    os << "winner: " << boolToString(actor.winner) << ", ";
    os << "name: " << actor.name << ", ";
    os << "film: " << actor.film;
    os << " }" << std::endl;
    return os;
}
