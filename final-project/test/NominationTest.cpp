#include "../src/Data/Nomination.hpp"
#include <iostream>

void constructorTest() {
    Nominations nomination(1, "1984", "fake", "0", "John Smith", "Moovie Name");
    nomination.print();
}

void toCsvTest() {
    Nominations nomination(127, "2008", "Award", "1", "Hailey Kincannon", "A Movie");
    std::cout << nomination.toCsvFormat() << std::endl;
}

int main() {
    constructorTest();
    toCsvTest();
    return 0;
}
