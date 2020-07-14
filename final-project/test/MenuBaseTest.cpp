#include "../src/UI/Menu/MenuBase.hpp"
#include <iostream>
#include <string>

void testPrintHeader() {
    MenuBase mb;
    mb.printMenu();
}

void testClear() {
    MenuBase mb;
    mb.getUserInfo();
}

void testIsNumber() {
    MenuBase mb;
    std::string test = "1234";
    bool result = mb.isNumber(&test);
    test = "abcd";
    std::cout << "is \"1234\" a number: " <<result << std::endl;
    result = mb.isNumber(&test);
    std::cout << "is \"abcd\" a number: " << result << std::endl;
}

int main() {
    testPrintHeader();
    testClear();
    testIsNumber();
}
