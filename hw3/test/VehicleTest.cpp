#include "../src/Vehicle.hpp"

void arrayPrintHelper(std::vector<Vehicle*>* vehicles) {
    for(int i = 0; i < vehicles->size(); i++) {
        std::cout << (*(*vehicles)[i]) << std::endl;
    } 
    std::cout << std::endl;  
}

std::vector<Vehicle*>* before() {
    Vehicle* test1 = new Vehicle(1000, "abc", "uvw");
    Vehicle* test2 = new Vehicle(2000, "xyz", "opq");
    Vehicle* test3 = new Vehicle(3000, "lmn", "def");
    std::vector<Vehicle*>* vehicles = new std::vector<Vehicle*>();
    vehicles->push_back(test1);
    vehicles->push_back(test3);
    vehicles->push_back(test2);
    return vehicles;
}

void testSorting() {
    std::vector<Vehicle*>* vehicles = before();
    std::cout << "size: " << vehicles->size() << std::endl;
    arrayPrintHelper(vehicles);
    quickSortString(vehicles, 0, (vehicles->size() - 1), true);
    arrayPrintHelper(vehicles);
    quickSortString(vehicles, 0, (vehicles->size() - 1), false);
    arrayPrintHelper(vehicles);
    quickSortYear(vehicles, 0, (vehicles->size() -1));
    arrayPrintHelper(vehicles);
    std::cout << std::endl;
}

void testBinarySearchRecModel() {
    std::cout << "testBinarySearchRecModel()" << std::endl;
    std::vector<Vehicle*>* vehicles = before();
    quickSortString(vehicles, 0, (vehicles->size() - 1), true);
    arrayPrintHelper(vehicles);
    Vehicle * result = binSearchRec(vehicles, 0, (vehicles->size() - 1), "opq", true);
    if( result != nullptr) {
        std::cout  << "result: "<< (*result) << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << std::endl;
}

void testBinarySearchRecMake() {
    std::cout << "testBinarySearchRecMake()" << std::endl;
    std::vector<Vehicle*>* vehicles = before();
    quickSortString(vehicles, 0, (vehicles->size() - 1), false);
    arrayPrintHelper(vehicles);
    Vehicle * result = binSearchRec(vehicles, 0, (vehicles->size() - 1), "xyz", false);
    if(result != nullptr) {
        std::cout << "result: "<< (*result) << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << std::endl;
}

void testBinarySearchRecYear() {
    std::cout << "testBinarySearchRecYear()" << std::endl;
    std::vector<Vehicle*>* vehicles = before();
    quickSortYear(vehicles, 0, (vehicles->size() - 1));
    arrayPrintHelper(vehicles);
    Vehicle * result = binSearchRec(vehicles, 0, (vehicles->size() - 1), 1000);
    if(result != nullptr) {
        std::cout << "result: " << (*result) << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << std::endl;
}

void testBinarySearchIterModel() {
    std::cout << "testBinarySearchIterModel()" << std::endl;
    std::vector<Vehicle*>* vehicles = before();
    quickSortString(vehicles, 0, (vehicles->size() - 1), true);
    arrayPrintHelper(vehicles);
    Vehicle * result = binSearchIter(vehicles, 0, (vehicles->size() - 1), "opq", true);
    if( result != nullptr) {
        std::cout  << "result: "<< (*result) << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << std::endl;
}

void testBinarySearchIterMake() {
    std::cout << "testBinarySearchIterMake()" << std::endl;
    std::vector<Vehicle*>* vehicles = before();
    quickSortString(vehicles, 0, (vehicles->size() - 1), false);
    arrayPrintHelper(vehicles);
    Vehicle * result = binSearchIter(vehicles, 0, (vehicles->size() - 1), "xyz", false);
    if(result != nullptr) {
        std::cout << "result: "<< (*result) << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << std::endl;
}

void testBinarySearchIterYear() {
    std::cout << "testBinarySearchIterYear()" << std::endl;
    std::vector<Vehicle*>* vehicles = before();
    quickSortYear(vehicles, 0, (vehicles->size() - 1));
    arrayPrintHelper(vehicles);
    Vehicle* result = binSearchIter(vehicles, 0, (vehicles->size() - 1), 1000);
    if(result != nullptr) {
        std::cout << "result: " << (*result) << std::endl;
    } else {
        std::cout << "failed" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    testSorting(); 
    testBinarySearchRecModel(); 
    testBinarySearchRecMake();
    testBinarySearchRecYear();
    testBinarySearchIterModel();
    testBinarySearchIterMake();
    testBinarySearchIterYear();
    return 0;
}
