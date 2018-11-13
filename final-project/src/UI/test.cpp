#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

void printLine(int col) {
    for(int i = 0; i < col; i++) std::cout << "*";
    std::cout << std::endl;
}

void printHeaderPeice(std::string title, int col) {
    std::cout << "*";
    int add = 0;
    int length = (col - title.length());
    if((length % 2) == 0) add = 1;
    length = (length / 2) - 2;
    for(int i = 0; i < length; i++) std::cout <<" ";
    std::cout << title;
    for(int i = 0; i < length + 2*add; i++) std::cout << " ";
    std::cout << "*" << std::endl;

}

void printHeader(std::string statement, int col) {
    printLine(col);
    printHeaderPeice("", col);
    printHeaderPeice(statement, col);
    printHeaderPeice("", col);
    printLine(col);
}



int main() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    printHeader("Hello Again World!" ,w.ws_col);
//    std::cout << "\x1B[2J\x1B[H";
    return 0;
}
