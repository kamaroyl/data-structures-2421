#include "../lib/util/StringsUtil.hpp"
#include <iostream>

void testToBool_true() {
    std::string test = "true";
    bool result = stringToBool(test);
    std::cout << boolToString(result) << std::endl;
}

void testToBool_false() {
    std::string test = "false";
    bool result = stringToBool(test);
    std::cout << boolToString(result) << std::endl;
}

void testToBool_invalid() {
    std::string test = "invalid";
    bool result = stringToBool(test);
    std::cout << boolToString(result) << std::endl;
}

void testToBool_numeric_true() {
    std::string test = "1";
    bool result = stringToBool(test);
    std::cout <<boolToString(result) << std::endl;
}

void testToBool_numeric_false() {
    std::string test = "0";
    bool result = stringToBool(test);
    std::cout << boolToString(result) << std::endl;
}

int main() {
    testToBool_true();
    testToBool_false();
    testToBool_invalid();
    testToBool_numeric_true();
    testToBool_numeric_false(); 
    return 0;
}
