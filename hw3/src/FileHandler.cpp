#include "FileHandler.hpp"

FileHandler::FileHandler(){
}

std::vector<Vehicle*>* FileHandler::readFromFile(std::string filePath) {
    std::ifstream fs(filePath);
    std::stringstream ss;
    int tmpYear = 0;
    int lineNumber = 0;
    std::string tmpMake = "";
    std::string tmpModel = "";
    std::vector<Vehicle*>* vehicles = new std::vector<Vehicle*>();
    if(fs.is_open()) {

        while(true) {
            std::string error;
            std::string tmp;
       
            if(!std::getline(fs, tmp)) {
                if(fs.eof()){
                    break;
                }
                std::cout << "failed to get line at " << lineNumber << std::endl;
                exit(1); 
            }

            lineNumber++;
           
            ss.str(tmp);
            ss >> tmpYear;
            ss.clear();
            if(ss.fail()) {
                std::cout << "failed to read in year int." << std::endl;
                ss >> error;
                std::cout << "Error: " << error << std::endl;
                exit(1);
            }

            if(!std::getline(fs, tmpMake)) {
                std::cout << "failed to get line at " << lineNumber << std::endl;
                exit(1);
            }
            
            lineNumber++;
            
            if(!std::getline(fs, tmpModel)) {
                std::cout << "failed to get line at " << lineNumber << std::endl;
                exit(1);
            }
            
            lineNumber++;
            Vehicle* tmpVehiclePointer = new Vehicle(tmpYear, tmpMake, tmpModel);
            vehicles->push_back(tmpVehiclePointer);
        }
        
        fs.close();
    }
    
    return vehicles;
}

