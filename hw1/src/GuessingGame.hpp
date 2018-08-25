#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H
#define LOWER_BOUND 0
#include <chrono>
/**
 *
 **/
class GuessingGame {

public:

   /********************************************************************************
    * Constructor should 
    * 1. create an integer array of length numberOfElements
    * 2. get the first numberOfElements random number from a Rand series - store in 
    *    array
    * 3. sort array
    ********************************************************************************/
    GuessingGame(long int n, long int m);
    explicit GuessingGame(long int n, long int m, unsigned long int rSeed=std::chrono::system_clock::now().time_since_epoch().count());

   /*
    * 1. Create copy of array
    * 2. for each item in guess, check if in array and remove element
    ********************/
    long compareGuessToStoredArray(long int *guess, long int length);
    void resetResultsSequence(); 
    void printGuessingGame(); 
private:
    long *randomSequence;
    long *resultSequence;
    long numberOfElements;

};
#endif
