#include "../src/Data/Actor.hpp"
#include <iostream>

void constructorTest() {
    Actor actor(0, "1876", "Hero", "1", "a Test", "film,A");
    actor.print();
    std::cout << actor;
}

void csvFormatTest() {
    Actor actor(0, "1876", "Hero", "1", "a Test", "film,A");
    std::cout << actor.toCsvFormat() << std::endl;
}

int main() {
    constructorTest();
    csvFormatTest();
    return  0;
}
