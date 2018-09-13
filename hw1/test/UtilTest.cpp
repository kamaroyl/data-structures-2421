#include <iostream>
#include "../src/Util.hpp"


bool testArrayCopy() { 
    long src[] = {1,2,3,4};
    long dst[4];
    shallowCopyArray(src, dst, 0, 3);
    return src[2] == dst[2];

}

bool arraySwap() {
    long src[] = {1,2,3,4};
    swap(&src[0],&src[3]);
    std::cout << "swapped array:";
    printArray(src, 4);
    return src[0] == 4 && src[3] == 1;
}

bool testSortArray() {
    long src[] = {3, 8, 5};
    long length = 3;
    std::cout << "Original Array: ";
    printArray(src, length);
    quickSort(src, 0, length - 1);
    std::cout << "sorted array:";
    printArray(src, length);
    return false;
}

int main() {
    std::cout << "true: " << true << std::endl;
    std::cout << "false: " << false << std::endl;
    std::cout << "testArrayCopy: " << testArrayCopy() << std::endl;
    testSortArray();
    arraySwap();
return 0;
}
