#include "../src/UI/Menu/MainMenu.hpp"
#include <string> 

void testMenuPrint() {
    MainMenu mm;
    mm.printMenu();
    std::string result = mm.getUserInfo();
    std::cout << "entered value was " << result << std::endl;

}

int main() {
    testMenuPrint();
    return 0;
}
