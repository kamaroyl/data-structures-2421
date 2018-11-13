#ifndef MY_HASH_TABLE_HPP
#define MY_HASH_TABLE_HPP
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "StringUtil.hpp"
class MyNode {
    private:
        std::string word;
        MyNode* next;
    
    public:
        MyNode();
        void setNext(MyNode* nextNode);
        MyNode* getNext();
        void setWord(std::string word);
        std::string getWord();
        bool isWord(std::string word);
};

class MyHashTable {
   static const int MAX_LENGTH = 1373;
    private:
        MyNode** table;
        int size;
        unsigned int hash(std::string word);

    public:
        MyHashTable();
        void insert(std::string word);
        bool contains(std::string word);
        void fromFile(std::string filePath);
        int getSize();
};

#endif
