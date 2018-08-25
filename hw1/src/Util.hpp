#ifndef UTIL_H
#define UTIL_H
    void swapArrayElements(long* array, long firstIndex, long secondIndex);
    long partition(long* array, long start, long end); 
    void iterativeQuickSort(long *array, long start, long end); 
    void shallowCopyArray(long* source, long* destination, long start, long end);
    bool arrayEquals(long * arrayOne, long * arrayTwo, long lengthOne, long lengthTwo);  
#endif
