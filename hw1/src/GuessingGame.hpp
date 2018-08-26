#ifndef GUESSING_GAME_H
#define GUESSING_GAME_H
#define LOWER_BOUND 1
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
    GuessingGame(long int n, long int m, unsigned long int rSeed);
    
    ~GuessingGame();

   /*
    * 1. Create copy of array
    * 2. for each item in guess, check if in array and remove element
    ********************/
    long compareGuess(long int *guess, long int length);
    void resetResultsSequence(); 
    void print(); 
private:
    long *randomSequence;
    long *resultSequence;
    long numberOfElements;

};
#endif
