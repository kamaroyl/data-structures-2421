#include "MyHashTable.hpp"
#include "StringUtil.hpp"

std::string bool2str(bool val) {
    if(val) return "true";
    return "false";
}

void getWordsFromBookFile(std::string filePath, MyHashTable* mht) {
    std::ifstream fs(filePath);
    int count = 0;
    int misspelled = 0;
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
            std::istringstream tmpLineBuffer(tmpLine);
            while(true) { 
                std::string tmpWord;
                std::getline(tmpLineBuffer, tmpWord, ' ');
                tmpWord = stripNonAlphaCharacters(tmpWord);
                if(tmpWord.length() > 0) {
                    bool test = mht->contains(tmpWord);  
                    count++;
                    if(!test) {
                        misspelled++;
                        std::cout << tmpWord << " is misspelled." <<std::endl;
                    }
                }
                if(tmpLineBuffer.eof()) {
                     break;
                }

            }
        }      
    }
    std::cout << "Size Of dictionary: " << mht->getSize() << std::endl;
    std::cout << "Total number of words in file under test: " << count << std::endl;
    std::cout << "Total number of misspelled words: " << misspelled << std::endl;
}

std::string getUserInput(std::string defaultAnswer, std::string question) {
    std::string input;
    std::cout << question << " default is " << defaultAnswer << std::endl;
    std::getline(std::cin, input);
    if(input.empty()) {
        input = defaultAnswer;
    }
    return input;
}

int main() {

    MyHashTable* mhtp = new MyHashTable();
    std::string path = getUserInput("dict.txt", "Give a dictionary path");
    mhtp->fromFile(path);
    path = getUserInput("check.txt", "Give a file to check");
    getWordsFromBookFile(path, mhtp);

    return 0;

}
