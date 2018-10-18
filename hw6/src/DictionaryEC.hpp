#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#define NOT_FOUND  -1

#include "DictEntry.h"
#include <iostream>
#include <fstream>
#include "DoublyLinkedList.hpp"
#include <string>

/*
 * Dictionary class, has a list of dictionary entries 
 */
class Dictionary {
    private:
        DoublyLinkedList dictEntries;
    public:
        Dictionary();

        //create dictionary from file
        void fromFile(std::string filepath);

        //sort dictEntries
        void sort();

        //returns position of Entry starting search from the front
        // and prints the total number of comparisons
        int findFromFront(std::string word);
        
        //returns position of Entry starting search from the back
        // and prints the total number of comparisons
        int findFromBack(std::string word);
        
        //print
        friend std::ostream& operator<<(std::ostream& stream, Dictionary &dictionary);
        
        //write the list in reverse order to a file specified
        //by filepath
        void printReverse(std::string filepath);

};
#endif
