#include "Dictionary.hpp"
#include <vector>


std::string askForFilePath(std::string defaultPath) {
    std::string input;
    std::cout << std::endl << "please give a file path. Will default to "  << defaultPath << std::endl;
    std::getline(std::cin, input);
    if(!input.empty()) {
        defaultPath = input;
    }
    return defaultPath;
}

std::vector<std::string> getSearchWords(std::string filepath) {
    std::vector<std::string> wordVector;
    std::ifstream fs(filepath);
    int lineNumber = 0;
    if(fs.is_open()) {
        while(true) {
            std::string tmp;
            if(!std::getline(fs,tmp)) {
                if(fs.eof()) {
                    break;
                }
                std::cout << "failed to read in word at line " << lineNumber << std::endl;
                std::cout << "continuing" << std::endl;
            }

            lineNumber++;
            wordVector.push_back(tmp);
        }
    }
    return wordVector;
}

int main() {
    //default file paths
    std::string defaultDictionaryFilePath = "../resource/dictionary.txt";
    std::string defaultSearchFilePath = "../resource/findwords.txt";
    std::string defaultOutputFilePath = "../out/revsorted.txt";

    Dictionary dictionary;
    //print initial state
    std::cout << dictionary << std::endl;

    //fill dictionary from provided file
    std::string fp = askForFilePath(defaultDictionaryFilePath);
    dictionary.fromFile(fp);

    //print filled dictionary
    std::cout << dictionary << std::endl << std::endl;

    //sort dictionary
    std::cout << "Sort" << std::endl << std::endl;
    dictionary.sort();
    std::cout << dictionary << std::endl;
    
    //initialize vector of all words to search for
    fp = askForFilePath(defaultSearchFilePath);
    std::vector<std::string> wordVector = getSearchWords(fp);
    int comparisonCount = 0;
    
    //search fro all words from the front and then from the back, and print the position
    //And thus the number pof comparisions, the word was found at
    for(std::vector<std::string>::iterator it = wordVector.begin(); it != wordVector.end(); ++it) {
        std::cout << std::endl << "looking for word " << *it << std::endl;
        comparisonCount = dictionary.findFromFront(*it);
        if(comparisonCount == NOT_FOUND) {
            std::cout << "didn't find the element, took max number of comparisons";
            std::cout << std::endl;
        } else {
            std::cout << "find from front took " << comparisonCount << " comparisons" << std::endl;
            comparisonCount = dictionary.findFromBack(*it);
            std::cout << "find from back took " << comparisonCount << " comparisons" << std::endl;
            std::cout << std::endl;
        }
    } 
    
    std::cout << "please give a file path for output file" << std::endl;
    fp = askForFilePath(defaultOutputFilePath);
    dictionary.printReverse(fp);  
    return 0;
  
}
