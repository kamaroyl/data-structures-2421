#include "Vehicle.hpp"


Vehicle::Vehicle(int year, std::string make, std::string model): year(year), make(make), model(model) {  
}

std::ostream& operator<<(std::ostream& stream, const Vehicle& vehicle) {
    stream << "Vehicle: { " ;
    stream << "make: " << vehicle.make << ", ";
    stream << "model: " << vehicle.model << ", ";
    stream << "year: " << vehicle.year << " }";
    return stream;
}

Vehicle* binSearchRec(std::vector<Vehicle*>* vehicles, int first, int last, std::string stringToCheck, bool isModel) { 
    if(last >= first) {
        int mid = first + (last - first)/2;
 
        std::string midValue = ((*vehicles)[mid])->make;
        if(isModel) {
            midValue = ((*vehicles)[mid])->model;
        }

        // is value mid value?
        if(midValue == stringToCheck) return ((*vehicles)[mid]);
        
        //check left
        if( midValue > stringToCheck) { 
            return binSearchRec(vehicles, first, (mid - 1), stringToCheck, isModel);
        }

        // else check right
        return binSearchRec(vehicles, (mid + 1), last, stringToCheck, isModel);
    }
    //No such element
    std::cout << "No such element" << std::endl;
    return nullptr;
}

Vehicle* binSearchRec(std::vector<Vehicle*>* vehicles, int first, int last, int year) {
    if(last >= first) {
        int mid = first + (last - first)/2;
        int midValue = ((*vehicles)[mid])->year; 
        //Is value mid value?
        if(midValue == year) return ((*vehicles)[mid]);

        //check left
        if(midValue > year) return binSearchRec(vehicles, first, (mid - 1), year);
        
        //else check right
        return binSearchRec(vehicles, (mid + 1), last, year);
    }
        
    std::cout << "No such Element" << std::endl;
    // no such element
    return nullptr;
}

Vehicle* binSearchIter(std::vector<Vehicle*>* vehicles, int first, int last, std::string stringToCheck, bool isModel) {
    while(last >= first) {
        int mid = first + (last - first)/2;
        std::string midValue = ((*vehicles)[mid])->make;
        if(isModel) {
            midValue = ((*vehicles)[mid])->model;
        }
        
        if(midValue == stringToCheck) return ((*vehicles)[mid]);

        if(midValue < stringToCheck) first = mid + 1;
        
        else last = mid - 1;
    }

    std::cout << "No such element" <<std::endl;
    return nullptr;
}

Vehicle* binSearchIter(std::vector<Vehicle*>* vehicles, int first, int last, int year) {
    while(last >= first) {
        int mid = first + (last - first)/2;
        int midValue = ((*vehicles)[mid])->year;

        if(midValue == year) return ((*vehicles)[mid]);

        if(midValue < year) first = mid + 1;

        else last = mid - 1;
    }
    
    std::cout << "No such element" << std::endl;
    return nullptr;
}

void swap(std::vector<Vehicle*>* vehicles, int a, int b) {
    Vehicle* tmp = (*vehicles)[a];
    (*vehicles)[a] = (*vehicles)[b];
    (*vehicles)[b] = tmp;
}

int partitionString(std::vector<Vehicle*>* vehicles, int l, int h, bool model) {
    std::string x = ((*vehicles)[h])->make;
    if(model) {
        x = ((*vehicles)[h])->model;
    }

    int i = l;
    
    for(int j = l; j < h; j++) {
        std::string y = ((*vehicles)[j])->make;
        if(model) {
            y = ((*vehicles)[j])->model;
        }
        if(y <= x) {
            swap(vehicles, i, j);
            i++;
        }
    }
    swap(vehicles, i, h);
    return i;
}

int partitionYear(std::vector<Vehicle*>* vehicles, int l, int h) {
    int i = l;
    int x = ((*vehicles)[h])->year;
    for(int j = l; j < h; j++) {
        int y = ((*vehicles)[j])->year;
        if(y <= x) {
            swap(vehicles, i, j);
            i++;
        }
    }
    swap(vehicles, i, h);
    return i;
}

/*
 * https://wiipedia.org/wiki/Quicksort
 */
void quickSortString(std::vector<Vehicle*>* vehicles, int l, int h, bool model) {
    if( l < h ) {
        int pivot = partitionString(vehicles, l, h, model);
        quickSortString(vehicles, l, (pivot - 1), model);
        quickSortString(vehicles, (pivot + 1), h, model);
    }
}

void quickSortYear(std::vector<Vehicle*>* vehicles, int l, int h) {
    if(l < h) {
        int pivot = partitionYear(vehicles, l, h);
        quickSortYear(vehicles, l, (pivot - 1));
        quickSortYear(vehicles, (pivot + 1), h);
    }
}
