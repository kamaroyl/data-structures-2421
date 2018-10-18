#include "DictionaryEC.hpp"

Dictionary::Dictionary() {}

void Dictionary::fromFile(std::string filepath) {
    std::ifstream fs(filepath);
    int lineNumber = 0; //keep track of which line in the file we are reading from
    
    if(fs.is_open()) {
        while(true) {
            std::string tmp;
            DictEntry dictEntry;
            
            if(!std::getline(fs,tmp)) {
                if(fs.eof()) {
                    break;
                }
                std::cout << "failed to read in word at line " << lineNumber << std::endl;
                std::cout << "continuing" << std::endl;
            }
        
            lineNumber++;
            
            dictEntry.setWord(tmp);
            this->dictEntries.insertAtBack(dictEntry);
        }
    }
}



std::ostream& operator<<(std::ostream& stream, Dictionary  &dictionary) {
    stream << "Dictionary { " << std::endl;
    stream << dictionary.dictEntries << std::endl;
    stream << "}";
    return stream; 
}

void Dictionary::sort( ) {
    this->dictEntries.sort();
}

int Dictionary::findFromFront(std::string word) {
    int len = 0;
    this->dictEntries.begin();
    
    while(true) {
        if(this->dictEntries.current().getWord() == word) return len;
        len++;
        if(!this->dictEntries.next()) return NOT_FOUND;
    }

    return NOT_FOUND;
}

int Dictionary::findFromBack(std::string word) {
    int len = 0;
    this->dictEntries.end();
    
    while(true) {
        if(this->dictEntries.current().getWord() == word) return len;
        len++;
        if(!this->dictEntries.prev()) return NOT_FOUND;
    }

    return NOT_FOUND;
}

void Dictionary::printReverse(std::string filepath) {
    std::ofstream reverseFile;
    reverseFile.open(filepath);
    this->dictEntries.end();
    while(true) {
        reverseFile << this->dictEntries.current().getWord() << " ";
        if(!this->dictEntries.prev()) break;
    }
    reverseFile.close();
}
