void swapArrayElements(long* array, long firstIndex, long secondIndex) {
    array[firstIndex] ^= array[secondIndex];
    array[secondIndex] ^= array[firstIndex];
    array[firstIndex] ^= array[secondIndex];
}

long partition(long* array, long start, long end) {
    long comparisonValue = array[end];
    long index = start - 1;
    
    for(int j = start; j <= end - 1; j++) {
        if(array[j] <= comparisonValue) {
            index++;
            swapArrayElements(array, index, j);
        }
    }
    swapArrayElements(array, index + 1, end);
    return index + 1;
}

/*
 *Iterative quick sort based on https://geeksforgeeks.org/iterative-quick-sort/
 */
void iterativeQuickSort(long *array, long start, long end) {
    long stack[end - start + 1];

    long top = 0;
    
    stack[top] = start;
    stack[++top] = end;
    
    while(top >= 0) {
        end = stack[top--];
        start = stack[top--];
        
        long pivot = partition(array, start, end);
        
        if(pivot - 1 > start) {
            stack[++top] = start;
            stack[++top] = pivot - 1;
        }
        
        if(pivot + 1 < end) {
            stack[++top] = pivot + 1;
            stack[++top] = end;
        }
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
