#include "Dictionary.hpp"
#include <iterator>
Dictionary::Dictionary() {
}

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
            this->dictEntries.push_back(dictEntry);
        }
    }
}

std::ostream& operator<<(std::ostream& stream, Dictionary  &dictionary) {
    stream << "Dictionary { " << std::endl;
    for(std::list<DictEntry>::iterator it = dictionary.dictEntries.begin(); it != dictionary.dictEntries.end(); ++it) {
        stream << it->getWord() << std::endl;
    }
    stream << "}";
    return stream; 
}

void Dictionary::sort( ) {
    this->dictEntries.sort();
}

int Dictionary::findFromFront(std::string word) {
    std::list<DictEntry>::iterator it;
    int len = 0;
    for(it = this->dictEntries.begin(); it != dictEntries.end(); ++it) {
        if(it->getWord() == word) return len;
        len++;
    }
    return NOT_FOUND;
}

int Dictionary::findFromBack(std::string word) {
    std::list<DictEntry>::reverse_iterator rit;
    int len = 0;
    for(rit = this->dictEntries.rbegin(); rit != this->dictEntries.rend(); ++rit) {
        if(rit->getWord() == word) return len;
        len++;
    }
    return NOT_FOUND;
}

void Dictionary::printReverse(std::string filepath) {
    std::list<DictEntry>::reverse_iterator rit;
    std::ofstream reverseFile;
    reverseFile.open(filepath);
    for(rit = this->dictEntries.rbegin(); rit != this->dictEntries.rend(); ++rit) {
        reverseFile << rit->getWord() << " ";
    }
    reverseFile.close();
}
