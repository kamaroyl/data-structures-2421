 
/* Game asks User to supply n number guesses. set of numbers can contain duplicates
 
               ------------------------------------------------
               |                                              ^
               |               | if not correct               |
               v               v     ^                        |
START -> ENTER Numbers-> GUESS STATE |->  Correct Play again? |-> EXIT
                      |              |                        |
                      v              v                        v
                    ERROR1         ERROR2                   ERROR3
**/
#include <iostream>
#include "GuessingGame.hpp"

/*
 * This method takes care of the user interaction pertaining to the number
 * of elements the user has to guess. The number must be greater than zero 
 ************************************************************************/
long enterNumberState() {
    long numberOfItems=0;
    bool complete = false;
    while(numberOfItems <= 0){
        if(numberOfItems < 0) std::cout << "Invalid number, please reenter";
        std::cout << "Enter the number of items to guess" << std::endl;
        if(!(std::cin >> numberOfItems)) {
            std::cout << "Please enter a valid integer" << std::endl;
            std::cin.clear();
        }
    }
    return numberOfItems;
}
/*
 * This method takes care of the user interaction pertaining to the maximum
 *  range of number the user must guess. The number must be greater than 0
 ************************************************************************/
long enterMaxRange() {
    unsigned long max=0;
    bool complete = false;
    while(max <= 0){
        if(max < 0) std::cout << "Invalid number, please reenter";
        std::cout << "Enter the max of the range (inclusive)" << std::endl;
        if(!(std::cin >> max)) {
            std::cout << "Please enter a valid integer" << std::endl;
            std::cin.clear();
        }
    }
    return max;
}

/*
 * This method takes care of the user interaction pertaining to the guesses.
 * Guesses must fall in (0,max], and there must be as many guesses as the user
 * specified previously.
 *************************************************************************/
void populateGuess(long *guess, long length, long max){
    long count = 0;
    std::cout << "Please enter " << length << " guesses between 0 and " << max << std::endl;
    while(count < length){
        std::cin >> guess[count];
        if( guess[count] > 0 && guess[count] <= max) {
            count ++;
        }
        else {
            std::cout << guess[count] << " falls outside of (0," << max << "] please enter a different number" << std::endl;
        }
    }
}

/*
 * Utility method to check the output of the guess array.
 */
void printGuessArray(long *guess, long length){
    for(long i = 0; i < length-1; i++){
        std::cout << guess[i] << ", ";
    }
    std::cout << guess[length-1] << std::endl;
}

int main() {
    short numberOfGuessesRemaining = 3;
    long *guess;
    std::cout << "Welcome to the guessing game!" << std::endl;
    
    long numberOfItems = enterNumberState();
    std::cout << "number of items: " << numberOfItems << std::endl;
    long max = enterMaxRange();
    std::cout << "upper bound: " << max << std::endl;
    GuessingGame *guessingGame = new GuessingGame(numberOfItems, max);
    while(numberOfGuessesRemaining > 0) {
        guess = new long[numberOfItems];
        populateGuess(guess, numberOfItems, max);
        printGuessArray(guess, numberOfItems);    
        
        // Guess object time
       numberOfGuessesRemaining--;
    }
    return 0;
}
