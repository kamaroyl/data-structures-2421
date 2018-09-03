#include <cassert>
#include <iostream>
#include <string>
#include "../src/ArrayBag.h"

std::string boolToString(bool value) {
    if(value) return "true";
    return "false";
}

void testConstructor() {
    std::cout << "testConstructor()" << std::endl;
    ArrayBag test1;    
    std::cout << test1;
    std::cout << std::endl;
}

void testAdd() {
    std::cout << "testAdd()" << std::endl;
    ArrayBag test1;
    std::cout << "before: " << test1;
    test1.add(11);
    std::cout << test1;
    std::cout << std::endl;
}

void testRemove() {
    std::cout << "testRemove()" << std::endl;
    ArrayBag test1;
    test1.add(11);
    std::cout << "before: " << test1;
    test1.remove(11);
    std::cout << test1;
    std::cout << std::endl;
}

void testUnion() {
    std::cout << "testUnion()" << std::endl;
    ArrayBag test1;
    ArrayBag test2;
    test1.add(1);
    test1.add(1);
    test1.add(2);
    test2.add(2);
    test2.add(3);
    std::cout << "test1: " << test1;
    std::cout << "test2: " << test2;
    ArrayBag test3 = test1 + test2;
    std::cout <<"union: " <<test3;
    std::cout << std::endl;
}

void testDifference() {
    std::cout << "testDifference()" << std::endl;
    ArrayBag test1;
    ArrayBag test2;
    for(int i = 0; i < 3; i++) test1.add(1);
    test1.add(2);
    test1.add(3);
    std::cout << "test1: " << test1;
    for(int i = 0; i < 2; i++) test2.add(1);
    test2.add(2);
    test2.add(2);
    std::cout << "test2: " << test2;
    ArrayBag test3 = test1 - test2;
    std::cout << "differenc: " << test3;
    std::cout << std::endl;
}

int main() {
    testConstructor();
    testAdd();
    testRemove();
    testUnion();
    testDifference();
    return 0;
}
