#include "../src/FileHandler.hpp"
#include "../src/Vehicle.hpp"

void arrayPrintHelper(std::vector<Vehicle*>* vehicles) {
    for(int i = 0; i < vehicles->size(); i++) {
        std::cout << (*(*vehicles)[i]) << std::endl;
    } 
}

void testReadFromFile() {
    FileHandler fh;
    std::vector<Vehicle*>* vehicles = fh.readFromFile("../resource/vehiclein.txt");
    arrayPrintHelper(vehicles);
}

int main() {
    testReadFromFile();
    return 0;
}
