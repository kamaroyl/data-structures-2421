#ifndef UTIL_H
#define UTIL_H
    void swap(long *a, long *b);
    long partition(long* array, long start, long end); 
    void quickSort(long *array, long start, long end); 
    void shallowCopyArray(long* source, long* destination, long start, long end);
    bool arrayEquals(long * arrayOne, long * arrayTwo, long lengthOne, long lengthTwo); 
    void printArray(long* array, long length); 
#endif
