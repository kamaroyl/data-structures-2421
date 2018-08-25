#include "../src/GuessingGame.hpp"
#include <iostream>

bool testConstructor() {
    GuessingGame gg(2,2,123456);
    gg.printGuessingGame();
    return false;
}

bool testGuessingGamePrint() {
    GuessingGame gg(10L,100L);
    gg.printGuessingGame();
}

bool testCompareGuessToStoredArrayWrong() {
    GuessingGame gg(2,2,123456);
    long guess[] = {0,2};
    gg.printGuessingGame();
    long numberRight = gg.compareGuessToStoredArray(guess, 2);
    gg.printGuessingGame();
    std::cout <<numberRight << std::endl;
    return false;
}

int main() {
    std::cout << "testing Print function " << std::endl;
    testGuessingGamePrint();
    std::cout << "testConstructor: " << testConstructor() << std::endl;
    std::cout << "testCompareGuessToStoredArrayWrong: " << testCompareGuessToStoredArrayWrong()  << std::endl;
    return 0;
}
