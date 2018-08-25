#include "GuessingGame.hpp"

#include "Util.hpp"
#include <chrono>
#include <iostream>
#include <random>


GuessingGame::GuessingGame(long numberOfElements, long rangeUpperBound, unsigned long seed) {
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<long> distribution(LOWER_BOUND, rangeUpperBound);
    this->numberOfElements = numberOfElements;
    this->randomSequence = new long[numberOfElements];
    this->resultSequence = new long[numberOfElements];
    
    for(int i = 0; i < numberOfElements - 1; i++) {
        this->randomSequence[i] = distribution(generator);
    }
    iterativeQuickSort(this->randomSequence, 0, (numberOfElements - 1));
    shallowCopyArray(this->randomSequence, this->resultSequence, 0, numberOfElements);    
}

long GuessingGame::compareGuessToStoredArray(long *guess, long length) {
    long count=0;
    iterativeQuickSort(guess, 0, length);
    for(long i = 0; i < length; i++) {
        for(long j = 0; j < this->numberOfElements; j++) {
            if(this->resultSequence[j] == guess[i]) {
                this->resultSequence[j] = -1;
                count++;
                break;
            }
        }
    }
    return count;
}

void GuessingGame::printGuessingGame() {
    std::cout << "GuessingGame : {" << std::endl;
    std::cout << "    numberOfElements: " << this->numberOfElements << "," << std::endl;
    std::cout << "    randomSequence: [";
    for(int i = 0; i < this->numberOfElements - 1; i++) {
        std::cout << this->randomSequence[i] << ", ";
    }
    std::cout << this->resultSequence[numberOfElements - 1] << "]," << std::endl;
    std::cout << "    resultSequence: [";
    for(int i = 0; i < this->numberOfElements - 1; i++) {
        std::cout << this->resultSequence[i] << ", ";
    }
    std::cout << this->resultSequence[numberOfElements - 1] << "]" << std::endl;
    std::cout << "}" << std::endl;
}

void GuessingGame::resetResultsSequence() {
    shallowCopyArray(this->randomSequence, this->resultSequence, 0, this->numberOfElements);
}

