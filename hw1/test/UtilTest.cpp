#include <iostream>
#include "../src/Util.hpp"


bool testArrayCopy() { 
long src[] = {1,2,3,4};
long dst[4];
shallowCopyArray(src, dst, 0, 3);
return src[2] == dst[2];

}

int main() {
    std::cout << "true: " << true << std::endl;
    std::cout << "false: " << false << std::endl;
    std::cout << "testArrayCopy: " << testArrayCopy() << std::endl;
return 0;
}
