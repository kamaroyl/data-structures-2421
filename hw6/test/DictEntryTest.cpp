#include "../src/DictEntry.h"
#include <iostream>

void testConstruction() {
    DictEntry de;
    de.setWord("Hello");
    de.setDef("A common greeting");
    std::cout << "word: " << de.getWord() << " def: " << de.getDef() << std::endl;
}


int main() {
    testConstruction();
    return 0;
}
