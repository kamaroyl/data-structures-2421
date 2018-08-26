#include "GuessingGame.hpp"

#include "Util.hpp"
#include <iostream>
#include <random>


GuessingGame::GuessingGame(long numberOfElements, long rangeUpperBound, unsigned long seed) {
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<long> distribution(1, rangeUpperBound);
    this->numberOfElements = numberOfElements;
    this->randomSequence = new long[numberOfElements];
    this->resultSequence = new long[numberOfElements];
    for(int i = 0; i < numberOfElements; i++) {
        this->randomSequence[i] = distribution(generator);
    }
    // Need to sort for ease of searching 
    quickSort(this->randomSequence, 0, (numberOfElements - 1));
    //copy so we can remove elements since there will be duplicates
    shallowCopyArray(this->randomSequence, this->resultSequence, 0, numberOfElements);    
}

GuessingGame::GuessingGame(long numberOfElements, long rangeUpperBound) {
    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<long> distribution(1, rangeUpperBound);
    this->numberOfElements = numberOfElements;
    this->randomSequence = new long[numberOfElements];
    this->resultSequence = new long[numberOfElements];
    
    for(int i = 0; i < numberOfElements - 1; i++) {
        this->randomSequence[i] = distribution(gen);
    }
    // Need to sort for ease of searching 
    quickSort(this->randomSequence, 0, (numberOfElements - 1));
    //copy so we can remove elements since there will be duplicates
    shallowCopyArray(this->randomSequence, this->resultSequence, 0, numberOfElements);    

}
 
GuessingGame::~GuessingGame() {
    delete[] this->randomSequence;
    delete[] this->resultSequence;
}

long GuessingGame::compareGuess(long *guess, long length) {
    long count=0;
    quickSort(guess, 0, length - 1);
    for(long i = 0; i < length; i++) {
        for(long j = 0; j < this->numberOfElements; j++) {
            if(this->resultSequence[j] == guess[i]) {
                this->resultSequence[j] = -1;
                count++;
                break;
            }
        }
    }
    this->resetResultsSequence();
    return count;
}

void GuessingGame::print() {
    std::cout << "GuessingGame : {" << std::endl;
    std::cout << "    numberOfElements: " << this->numberOfElements << "," << std::endl;
    std::cout << "    randomSequence: ";
    printArray(this->randomSequence, this->numberOfElements);
    std::cout << "    resultSequence: ";
    printArray(this->randomSequence, this->numberOfElements);
    std::cout << "}" << std::endl;
}

void GuessingGame::resetResultsSequence() {
    shallowCopyArray(this->randomSequence, this->resultSequence, 0, this->numberOfElements);
}

