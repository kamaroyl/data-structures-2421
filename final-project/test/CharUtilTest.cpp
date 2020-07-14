#include "../lib/util/CharUtil.hpp"
#include <iostream>
#include <cassert>

void testAbsNegative() {
    char a = -2;
    unsigned char b = abs(a);
    assert(b == 2);
    std::cout << (int)b << " should be 2" << std::endl;
}

int main() {
    testAbsNegative();
    return 0;
}
