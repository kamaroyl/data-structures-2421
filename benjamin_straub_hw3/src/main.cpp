#include <fstream>
#include <sstream>
#include "FileHandler.hpp"
#include "Vehicle.hpp"


bool continueQuestion() {
    char choice = 'n';
    std::cout << "Would you like to run again? y/n" << std::endl;
    while(true) {
        std::cin >> choice;
        if(choice == 'y') return true;
        if(choice == 'n') return false;
        std::cin.clear();
        std::cout << "Please enter 'y' or 'n'." << std::endl;
    }
}

int main() {
    std::string input;
    std::string path = "./resource/vehiclein.txt";
    std::stringstream stream;
    Vehicle * result;

    std::cout << "Give a filepath to a file with vehicle data; Data must be line delimited and be in the order: " << std::endl;
    std::cout << "year" << std::endl;
    std::cout << "make" << std::endl;
    std::cout << "model" << std::endl;
    std::cout << "If no path is given, it will default to ./resouce/vehiclein.txt";
    std::cout << std::endl;

    std::getline(std::cin, input);
    if(!input.empty()) {
        stream.str(input);
        stream >> path;   
        stream.clear(); 
    }

    std::cout << "Path will be: " << path << std::endl;
    FileHandler fh;
    std::vector<Vehicle*>* vehicles = fh.readFromFile(path);
    
    std::cout << "Vehicles: [" << std::endl;
    for(int i = 0; i < vehicles->size(); i++) {
        std::cout << (*(*vehicles)[i]) << std::endl;
    }
    std::cout << "]" << std::endl;    

    int fieldToSortOn = 0;
    int iterationOrRecursion = 0;
    bool willContinue = true;

    while(willContinue) {
        std::cout << "what would you like to sort by? Please enter 1, 2 or 3" << std::endl;
        std::cout << "1. year" << std::endl;
        std::cout << "2. make" << std::endl;
        std::cout << "3. model" << std::endl;

        while(fieldToSortOn < 1 || fieldToSortOn > 3) {
            std::getline(std::cin, input);
            if(!input.empty()) {
                stream.str(input);
                stream >> fieldToSortOn;
                stream.clear();
                if(stream.fail()) {
                    std::string error;
                    stream >> error;
                    std::cout << error << "is not a valid option, please input 1 - 3" << std::endl;
                }
            }
        }
        
        // Sort on year
        if(fieldToSortOn == 1) {
            quickSortYear(vehicles, 0, (vehicles->size() - 1));
        }

        if(fieldToSortOn == 2) {
            quickSortString(vehicles, 0, (vehicles->size() - 1), false);
        }
        
        if(fieldToSortOn == 3) {
            quickSortString(vehicles, 0, (vehicles->size() -1), true);
        }
        
        std::cout << "Would you like to do a search by: " <<std::endl;
        std::cout << "1. Iteration" << std::endl;
        std::cout << "2. Recursion" << std::endl;

        while(iterationOrRecursion < 1 || iterationOrRecursion > 2) {
            std::getline(std::cin, input);
            if(!input.empty()) {
                stream.str(input);
                stream >> iterationOrRecursion;
                stream.clear();
                if(stream.fail()) {
                    std::string error;
                    stream >> error;
                    std::cout << error << "is not a valid option, please input 1 or 2" << std::endl;
                }  
            }
        }
        std::cout << "Please enter the value you would like to look for" << std::endl;
        int intSearchValue;
        std::string stringSearchValue;

        std::getline(std::cin, stringSearchValue); 
        if(!stringSearchValue.empty()) {
            if(fieldToSortOn == 1) {
                stream.str(stringSearchValue);
                stream >> intSearchValue;
                stream.clear();
            }
        }
        
        //Sort on year
        if(fieldToSortOn == 1) {
            if(iterationOrRecursion == 1) {
                result = binSearchRec(vehicles, 0, (vehicles->size() - 1), intSearchValue);
            }
            else result = binSearchIter(vehicles, 0, (vehicles->size() - 1), intSearchValue);
        }
        
        //sort on Make or Model
        if(fieldToSortOn == 2 || fieldToSortOn == 3) {
            if(iterationOrRecursion == 1) {
                result = binSearchRec(vehicles, 0, (vehicles->size() - 1), stringSearchValue, (fieldToSortOn == 3));
            }
            else result = binSearchIter(vehicles, 0, (vehicles->size() - 1), stringSearchValue, (fieldToSortOn == 3));
        }
        
        if(result == nullptr) std::cout << "No Element found" << std::endl;
        else std::cout << "result: " << (*result) << std::endl;
        
        willContinue = continueQuestion();   
        //reset 
        fieldToSortOn = 0;
        iterationOrRecursion = 0;
        intSearchValue = 0;
        stringSearchValue = "";
        input = "";
    }
    
    std::cout << "Goodbye" << std::endl;    
    return 0;
}
