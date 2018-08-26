#include "../src/GuessingGame.hpp"
#include <iostream>

bool testConstructor() {
    GuessingGame gg(4,2,123456);
    gg.print();
    return true;
}

bool testCompareGuessWrong() {
    GuessingGame gg(2,2, 543876);
    long guess[] = {0,1};
    long numberRight = gg.compareGuess(guess, 2);
    return numberRight == 1;
}

void testCompareGuessRight() {
    std::cout << "starting CompareGuess correct test" << std::endl;
    GuessingGame gg(2,2,543876);
    gg.print();
    long guess[] = {1,1};
    long numberRight = gg.compareGuess(guess, 2);
    gg.print();
    std::cout << "Expected 2 to be right, and " << numberRight << "was actually correct" << std::endl;
}

void testCompareGuessRepeatedGuess() {
    std::cout << "starting Repeated Guess test" << std::endl;
    GuessingGame gg(2,5, 16264);
    std::cout <<"BEFORE: " << std::endl;
    gg.print();
    long guess[] = {2,2};
    long numberRight = gg.compareGuess(guess, 2);
    std::cout <<"After: " << std::endl;
    gg.print();
    std::cout << "Number right: " << numberRight << std::endl;

}

int main() {
    std::cout << "testConstructor: " << testConstructor() << std::endl;
    std::cout << "testCompareGuessWrong: " << testCompareGuessWrong()  << std::endl;
    testCompareGuessRight();
    testCompareGuessRepeatedGuess();
    return 0;
}
