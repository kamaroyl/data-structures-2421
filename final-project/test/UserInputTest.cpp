#include "../src/UI/UserInput.hpp"

void testUserInput() {
    UserInput ui;
    std::string filepath = ui.getUserInput(validateFilePath);
    std::cout << filepath << std::endl;
}

int main() {
    testUserInput();
    return 0;
}
