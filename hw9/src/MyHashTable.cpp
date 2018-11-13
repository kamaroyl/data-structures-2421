#include "MyHashTable.hpp"

MyNode::MyNode():next(nullptr), word("") {
}

void MyNode::setWord(std::string word) {
    this->word = word;
}

void MyNode::setNext(MyNode* next) {
    this->next = next;
}

MyNode* MyNode::getNext() {
    return this->next;
}

std::string MyNode::getWord() {
    return this->word;
}

bool MyNode::isWord(std::string word) {
    return (this->word == word);
}

MyHashTable::MyHashTable() {
    this->table = new MyNode*[MAX_LENGTH];
    for(int i = 0; i < MAX_LENGTH; i++) {
        this->table[i] = nullptr;
    }
    this->size = 0;
}

//djb2
unsigned int MyHashTable::hash(std::string word) {
    unsigned int hashed = 5381;
    for(int i = 0; i < word.length(); i++) {
        hashed = ((hashed << 5) + hashed) + word[i];
    }
    return hashed%MAX_LENGTH;
}

void MyHashTable::insert(std::string word) {
    unsigned int hashKey = this->hash(word);
    MyNode* current = this->table[hashKey];
    if(current == nullptr) {
        current = new MyNode();
        current->setWord(word);
        this->table[hashKey] = current;
        this->size++;
        return;
    } 
    
    while(current->getNext()){
        current = current->getNext();
    }
    
    MyNode* addNode = new MyNode();
    addNode->setWord(word);
    current->setNext(addNode);
    this->size++;
}

bool MyHashTable::contains(std::string word) {
    unsigned int hashKey = this->hash(word);
    MyNode* current = this->table[hashKey];
    if(current == nullptr) {
        return false;
    }
    
    while(current) {
        if(current->getWord() == word) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

void MyHashTable::fromFile(std::string filePath) {
    std::ifstream fs(filePath);
    int lineNumber = 0;
    
    if(fs.is_open()) {
        while(true) {
            std::string tmpLine;
            if(!std::getline(fs, tmpLine)) {
                if(fs.eof()) {
                    break;
                }

                std::cout << "failed to read in line at " << lineNumber << std::endl;
                lineNumber++;
                continue;
            }
            lineNumber++;
            while(true) { 
                std::string tmpWord;
                std::istringstream tmpLineBuffer(tmpLine);
                std::getline(tmpLineBuffer, tmpWord, ' ');
                tmpWord = stripNonAlphaCharacters(tmpWord);
                //std::cout <<tmpWord << std::endl;
                if(tmpWord.length() > 0) {
                    this->insert(tmpWord);
                }
                if(tmpLineBuffer.eof()) {
                     break;
                }

            }
        }      
    }
}

int MyHashTable::getSize() {
    return this->size;
}
