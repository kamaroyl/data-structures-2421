#include "Nomination.hpp"
#include "../../lib/util/StringsUtil.hpp"
Nominations::Nominations(unsigned int index, std::string year, std::string award, std::string winner, std::string name, std::string film) {
    this->index = index;
    this->year = (unsigned short) std::stoi(year);
    this->award = award;
    this->winner = stringToBool(winner);
    this->name = name;
    this->film = film;
}

unsigned int Nominations::getIndex() {
    return this->index;
}

unsigned short Nominations::getYear() {
    return this->year;
}

std::string Nominations::getAward() {
    return this->award;
}

bool Nominations::getWinner() {
    return this->winner;
}

std::string Nominations::getName() {
    return this->name;
}

std::string Nominations::getFilm() {
    return this->film;
}

void Nominations::print() {
    std::cout << "Nominations: { ";
    std::cout << "index: " << this->index << ", ";
    std::cout << "year: " << this->year << ", ";
    std::cout << "award: " << this->award << ", ";
    std::cout << "winner: " << boolToString(this->winner) << ", ";
    std::cout << "name: " << this->name << ", ";
    std::cout << "film: " << this->film;
    std::cout << " }" << std::endl;
}

std::string Nominations::toCsvFormat() {
    std::stringstream ss;
    ss << this->year << ",";
    ss << this->award << ",";
    ss << this->winner << ",";
    ss << this->name << ",";
    ss << this->film;
    return ss.str();
}
