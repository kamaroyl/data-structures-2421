#include "MenuBase.hpp"

MenuBase::MenuBase() {}

void MenuBase::printLine(int col) {
    for(int i = 0; i < col; i++) std::cout << "*";
}

void MenuBase::printHeaderPiece(std::string title, int col) {
    std::cout << "*";
    int add = 0;
    int length = (col - title.length());
    if((length % 2) == 0) add = 1;
    length = (length / 2) - 2;
    for(int i = 0; i < length; i++) std::cout << " ";
    if(title.length() < 1 && add != 1) std::cout << "   ";
    std::cout << title;
    for(int i = 0; i < length + 2 * add; i++) std::cout << " ";
    std::cout << "*" << std::endl; 
}

void MenuBase::printHeader(std::string statement) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int col = w.ws_col;
    printLine(col);
    printHeaderPiece("", col);
    printHeaderPiece(statement, col);
    printHeaderPiece("", col);
    printLine(col);
}

// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool MenuBase::isNumber(std::string* s) {
    std::string::const_iterator it = s->begin();
    while(it != s->end() && std::isdigit(*it)) ++it;
    return !s->empty() && it == s->end();
}

// https://stackoverflow.com/questions/447206/c-isfloat-function
bool MenuBase::isFloat(std::string* s) {
    std::istringstream iss(*s);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

void MenuBase::clearScreen() {
    std::cout << "\x1B[2J\x1B[H";
}
    
void MenuBase::printMenu() {
    this->printHeader("not implemented");
}

std::string MenuBase::getUserInfo() {
    this->clearScreen();
    return "heck";
}

