#include <iostream>

void printArray(long * array, long length){
    std::cout << "[";
    for(int i = 0; i < length - 1; i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << array[length - 1] << "]" << std::endl;
}

void swap(long *a, long *b) {
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

long partition(long *array, long l, long h) {
    int x = array[h];
    int i = (l - 1) ;
    
    for(int j = l; j < h - 1; j++) {
        if(array[j] <= x) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[h]);
    return (i + 1);
}

/*
 * https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Quicksort
 */
void quickSort(long * array, long l, long h) {
    if( l < h ) {
        long pivot = partition(array, l, h);
        quickSort(array, l, (pivot - 1));
        quickSort(array, (pivot + 1), h);
    }
}

void shallowCopyArray(long* source, long* destination, long start, long end) {
    for(long i = start; i < end; i++) {
        destination[i] = source[i];
    }
}

/*
 * Checks the elements of two arrays are equal
 *********************************************/
bool arrayEquals(long * arrayOne, long * arrayTwo, long lengthOne, long lengthTwo) {
    if ( lengthOne != lengthTwo) return false;
    for(int i = 0; i < lengthOne; i++) { 
        if(arrayOne[i] != arrayTwo[i]) return false;    
    }
    return true;
}
