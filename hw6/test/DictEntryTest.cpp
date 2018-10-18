#include "../src/DictEntry.h"
#include <iostream>

void testConstruction() {
    DictEntry de;
    de.setWord("Hello");
    de.setDef("A common greeting");
    std::cout << "word: " << de.getWord() << " def: " << de.getDef() << std::endl;
}

void testAssignment() {
    DictEntry de;
    de.setWord("goodbye");
    de.setDef("a common salutation");
    DictEntry de2 = de;
    std::cout << "word: " << de2.getWord() << " def: " << de2.getDef() << std::endl;
}


int main() {
    testConstruction();
    testAssignment();
    return 0;
}
